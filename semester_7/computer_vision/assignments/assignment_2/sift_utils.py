"""
Utility functions for SIFT

The submittee has taken reference from the following sources:
https://github.com/rmislam/PythonSIFT
"""
import logging
from functools import cmp_to_key

from cv2 import INTER_LINEAR, INTER_NEAREST, GaussianBlur, KeyPoint, resize, subtract
from numpy import (
    all,
    any,
    arctan2,
    array,
    cos,
    deg2rad,
    dot,
    exp,
    float32,
    floor,
    full,
    isnan,
    log,
    logical_and,
    nan,
    pi,
    rad2deg,
    roll,
    round,
    sin,
    sqrt,
    stack,
    trace,
    unravel_index,
    where,
    zeros,
)
from numpy.linalg import det, lstsq, norm

logger = logging.getLogger(__name__)
float_tolerance = 1e-7


def extrema_interpolated_fit(
    i,
    j,
    image_index,
    octave_index,
    num_intervals,
    dog_images_in_octave,
    sigma,
    contrast_threshold,
    image_border_width,
    eigenvalue_ratio=10,
    num_attempts_until_convergence=5,
):
    logger.debug("Localizing scale-space extrema...")
    extremum_is_outside_image = False
    image_shape = dog_images_in_octave[0].shape
    for attempt_index in range(num_attempts_until_convergence):
        first_image, second_image, third_image = dog_images_in_octave[
            image_index - 1 : image_index + 2
        ]
        pixel_cube = (
            stack(
                [
                    first_image[i - 1 : i + 2, j - 1 : j + 2],
                    second_image[i - 1 : i + 2, j - 1 : j + 2],
                    third_image[i - 1 : i + 2, j - 1 : j + 2],
                ]
            ).astype("float32")
            / 255.0
        )
        gradient = compute_gradient_at_center_pixel(pixel_cube)
        hessian = compute_hessian_at_center_pixel(pixel_cube)
        extremum_update = -lstsq(hessian, gradient, rcond=None)[0]
        if (
            abs(extremum_update[0]) < 0.5
            and abs(extremum_update[1]) < 0.5
            and abs(extremum_update[2]) < 0.5
        ):
            break
        j += int(round(extremum_update[0]))
        i += int(round(extremum_update[1]))
        image_index += int(round(extremum_update[2]))
        # make sure the new pixel_cube will lie entirely within the image
        if (
            i < image_border_width
            or i >= image_shape[0] - image_border_width
            or j < image_border_width
            or j >= image_shape[1] - image_border_width
            or image_index < 1
            or image_index > num_intervals
        ):
            extremum_is_outside_image = True
            break
    if extremum_is_outside_image:
        logger.debug(
            "Updated extremum moved outside of image before reaching convergence. Skipping..."
        )
        return None
    if attempt_index >= num_attempts_until_convergence - 1:
        logger.debug(
            "Exceeded maximum number of attempts without reaching convergence for this extremum. Skipping..."
        )
        return None
    functionValueAtUpdatedExtremum = pixel_cube[1, 1, 1] + 0.5 * dot(
        gradient, extremum_update
    )
    if abs(functionValueAtUpdatedExtremum) * num_intervals >= contrast_threshold:
        xy_hessian = hessian[:2, :2]
        xy_hessian_trace = trace(xy_hessian)
        xy_hessian_det = det(xy_hessian)
        if (
            xy_hessian_det > 0
            and eigenvalue_ratio * (xy_hessian_trace**2)
            < ((eigenvalue_ratio + 1) ** 2) * xy_hessian_det
        ):
            # Contrast check passed -- construct and return OpenCV KeyPoint object
            keypoint = KeyPoint()
            keypoint.pt = (
                (j + extremum_update[0]) * (2**octave_index),
                (i + extremum_update[1]) * (2**octave_index),
            )
            keypoint.octave = (
                octave_index
                + image_index * (2**8)
                + int(round((extremum_update[2] + 0.5) * 255)) * (2**16)
            )
            keypoint.size = (
                sigma
                * (2 ** ((image_index + extremum_update[2]) / float32(num_intervals)))
                * (2 ** (octave_index + 1))
            )  # octave_index + 1 because the input image was doubled
            keypoint.response = abs(functionValueAtUpdatedExtremum)
            return keypoint, image_index
    return None


def compute_gradient_at_center_pixel(pixel_array):
    dx = 0.5 * (pixel_array[1, 1, 2] - pixel_array[1, 1, 0])
    dy = 0.5 * (pixel_array[1, 2, 1] - pixel_array[1, 0, 1])
    ds = 0.5 * (pixel_array[2, 1, 1] - pixel_array[0, 1, 1])
    return array([dx, dy, ds])


def compute_hessian_at_center_pixel(pixel_array):
    center_pixel_value = pixel_array[1, 1, 1]
    dxx = pixel_array[1, 1, 2] - 2 * center_pixel_value + pixel_array[1, 1, 0]
    dyy = pixel_array[1, 2, 1] - 2 * center_pixel_value + pixel_array[1, 0, 1]
    dss = pixel_array[2, 1, 1] - 2 * center_pixel_value + pixel_array[0, 1, 1]
    dxy = 0.25 * (
        pixel_array[1, 2, 2]
        - pixel_array[1, 2, 0]
        - pixel_array[1, 0, 2]
        + pixel_array[1, 0, 0]
    )
    dxs = 0.25 * (
        pixel_array[2, 1, 2]
        - pixel_array[2, 1, 0]
        - pixel_array[0, 1, 2]
        + pixel_array[0, 1, 0]
    )
    dys = 0.25 * (
        pixel_array[2, 2, 1]
        - pixel_array[2, 0, 1]
        - pixel_array[0, 2, 1]
        + pixel_array[0, 0, 1]
    )
    return array([[dxx, dxy, dxs], [dxy, dyy, dys], [dxs, dys, dss]])


def get_keypoint_orientations(
    keypoint,
    octave_idx,
    gaussian_img,
    radius_factor=3,
    bins_count=36,
    peak_ratio=0.8,
    scale_factor=1.5,
):
    """Compute orientations for each keypoint"""
    keypoints_orientations = []
    img_shape = gaussian_img.shape

    scale = scale_factor * keypoint.size / float32(2 ** (octave_idx + 1))
    radius = int(round(radius_factor * scale))
    weight_factor = -0.5 / (scale**2)
    raw_hist = zeros(bins_count)
    smooth_hist = zeros(bins_count)

    for i in range(-radius, radius + 1):
        region_y = int(round(keypoint.pt[1] / float32(2**octave_idx))) + i
        if region_y > 0 and region_y < img_shape[0] - 1:
            for j in range(-radius, radius + 1):
                region_x = int(round(keypoint.pt[0] / float32(2**octave_idx))) + j
                if region_x > 0 and region_x < img_shape[1] - 1:
                    dx = (
                        gaussian_img[region_y, region_x + 1]
                        - gaussian_img[region_y, region_x - 1]
                    )
                    dy = (
                        gaussian_img[region_y - 1, region_x]
                        - gaussian_img[region_y + 1, region_x]
                    )
                    gradient_magnitude = sqrt(dx * dx + dy * dy)
                    gradient_orientation = rad2deg(arctan2(dy, dx))
                    weight = exp(weight_factor * (i**2 + j**2))
                    hist_idx = int(round(gradient_orientation * bins_count / 360.0))
                    raw_hist[hist_idx % bins_count] += weight * gradient_magnitude

    for n in range(bins_count):
        smooth_hist[n] = (
            6 * raw_hist[n]
            + 4 * (raw_hist[n - 1] + raw_hist[(n + 1) % bins_count])
            + raw_hist[n - 2]
            + raw_hist[(n + 2) % bins_count]
        ) / 16.0
    orientation_max = max(smooth_hist)
    orientation_peaks = where(
        logical_and(
            smooth_hist > roll(smooth_hist, 1),
            smooth_hist > roll(smooth_hist, -1),
        )
    )[0]
    for peak_idx in orientation_peaks:
        peak_value = smooth_hist[peak_idx]
        if peak_value >= peak_ratio * orientation_max:
            left_value = smooth_hist[(peak_idx - 1) % bins_count]
            right_value = smooth_hist[(peak_idx + 1) % bins_count]
            interpolated_peak_idx = (
                peak_idx
                + 0.5
                * (left_value - right_value)
                / (left_value - 2 * peak_value + right_value)
            ) % bins_count
            orientation = 360.0 - interpolated_peak_idx * 360.0 / bins_count
            if abs(orientation - 360.0) < float_tolerance:
                orientation = 0
            new_keypoint = KeyPoint(
                *keypoint.pt,
                keypoint.size,
                orientation,
                keypoint.response,
                keypoint.octave
            )
            keypoints_orientations.append(new_keypoint)
    return keypoints_orientations


def get_histogram_bins(
    keypoint,
    gaussian_img,
    theta,
    hist_dim,
    window_dim,
    weight_factor,
    degree_bins,
):
    half_dim = window_dim // 2
    img_rows, img_cols = gaussian_img.shape
    row_bins, col_bins, magnitudes, orientation_bins = [], [], [], []

    sin_theta = sin(theta)
    cos_theta = cos(theta)

    def within_bounds(val, lower, upper):
        return lower <= val <= upper

    def compute_bin(row, col):
        nonlocal row_bins, col_bins, magnitudes, orientation_bins
        row_rot = col * sin_theta + row * cos_theta
        col_rot = col * cos_theta - row * sin_theta
        row_bin = (row_rot / hist_dim) + 0.5 * window_dim - 0.5
        col_bin = (col_rot / hist_dim) + 0.5 * window_dim - 0.5

        if within_bounds(row_bin, -1, window_dim) and within_bounds(
            col_bin, -1, window_dim
        ):
            window_row = int(round(keypoint[1] + row))
            window_col = int(round(keypoint[0] + col))

            if within_bounds(window_row, 0, img_rows - 1) and within_bounds(
                window_col, 0, img_cols - 1
            ):
                dx = (
                    gaussian_img[window_row, window_col + 1]
                    - gaussian_img[window_row, window_col - 1]
                )
                dy = (
                    gaussian_img[window_row - 1, window_col]
                    - gaussian_img[window_row + 1, window_col]
                )
                gradient_magnitude = sqrt(dx * dx + dy * dy)
                gradient_orientation = rad2deg(arctan2(dy, dx)) % 360
                weight = exp(
                    weight_factor
                    * ((row_rot / hist_dim) ** 2 + (col_rot / hist_dim) ** 2)
                )
                row_bins.append(row_bin)
                col_bins.append(col_bin)
                magnitudes.append(weight * gradient_magnitude)
                orientation_bins.append((gradient_orientation - theta) * degree_bins)

    for row in range(-half_dim, half_dim + 1):
        for col in range(-half_dim, half_dim + 1):
            compute_bin(row, col)

    return row_bins, col_bins, magnitudes, orientation_bins


def process_bins(
    row_bin_list,
    col_bin_list,
    magnitude_list,
    orientation_bin_list,
    num_bins,
    histogram_tensor,
):
    for row_bin, col_bin, magnitude, orientation_bin in zip(
        row_bin_list, col_bin_list, magnitude_list, orientation_bin_list
    ):
        # Smoothing via trilinear interpolation
        row_bin_floor, col_bin_floor, orientation_bin_floor = floor(
            [row_bin, col_bin, orientation_bin]
        ).astype(int)
        row_fraction, col_fraction, orientation_fraction = (
            row_bin - row_bin_floor,
            col_bin - col_bin_floor,
            orientation_bin - orientation_bin_floor,
        )
        if orientation_bin_floor < 0:
            orientation_bin_floor += num_bins
        if orientation_bin_floor >= num_bins:
            orientation_bin_floor -= num_bins

        c1 = magnitude * row_fraction
        c0 = magnitude * (1 - row_fraction)
        c11 = c1 * col_fraction
        c10 = c1 * (1 - col_fraction)
        c01 = c0 * col_fraction
        c00 = c0 * (1 - col_fraction)
        c111 = c11 * orientation_fraction
        c110 = c11 * (1 - orientation_fraction)
        c101 = c10 * orientation_fraction
        c100 = c10 * (1 - orientation_fraction)
        c011 = c01 * orientation_fraction
        c010 = c01 * (1 - orientation_fraction)
        c001 = c00 * orientation_fraction
        c000 = c00 * (1 - orientation_fraction)

        histogram_tensor[
            row_bin_floor + 1, col_bin_floor + 1, orientation_bin_floor
        ] += c000
        histogram_tensor[
            row_bin_floor + 1,
            col_bin_floor + 1,
            (orientation_bin_floor + 1) % num_bins,
        ] += c001
        histogram_tensor[
            row_bin_floor + 1, col_bin_floor + 2, orientation_bin_floor
        ] += c010
        histogram_tensor[
            row_bin_floor + 1,
            col_bin_floor + 2,
            (orientation_bin_floor + 1) % num_bins,
        ] += c011
        histogram_tensor[
            row_bin_floor + 2, col_bin_floor + 1, orientation_bin_floor
        ] += c100
        histogram_tensor[
            row_bin_floor + 2,
            col_bin_floor + 1,
            (orientation_bin_floor + 1) % num_bins,
        ] += c101
        histogram_tensor[
            row_bin_floor + 2, col_bin_floor + 2, orientation_bin_floor
        ] += c110
        histogram_tensor[
            row_bin_floor + 2,
            col_bin_floor + 2,
            (orientation_bin_floor + 1) % num_bins,
        ] += c111
