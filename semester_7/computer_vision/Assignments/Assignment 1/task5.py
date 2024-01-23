"""
Muhammad Umer, Muhammad Ahmed Mohsin, Muhammad Saad
CMS IDs: 345834, 333060, 333414
Class: BEE-12

Task 5: Take any image and detect the corners by employing Harris corner detection.
"""

import cv2
import numpy as np
from numba import jit


# Reused from Task 1
def get_gaussian_kernel(size, sigma=-1):
    """
    Generates a Gaussian kernel of the specified size and sigma.

    If sigma = -1, then sigma is automatically calculated
    as (size - 1) / 6.0, as per the OpenCV documentation.
    """
    if sigma < 0:
        sigma = (size - 1) / 6.0

    # Generate a grid using the specified size
    axis = np.linspace(-(size - 1) / 2.0, (size - 1) / 2.0, size)
    x, y = np.meshgrid(axis, axis)

    # Create the kernel
    gaussian_kernel = np.exp(-0.5 * (x**2 + y**2) / sigma**2)

    return gaussian_kernel / np.sum(gaussian_kernel)


@jit(nopython=True)
def non_max_suppression(H_response, win_height, win_width):
    """
    Performs non-maximum suppression on the Harris response.
    """
    for i in range(win_height, H_response.shape[0] - win_height):
        for j in range(win_width, H_response.shape[1] - win_width):
            if H_response[i, j] == 0:
                continue
            H_slice = H_response[
                i - win_height : i + win_height + 1, j - win_width : j + win_width + 1
            ]
            if H_response[i, j] != H_slice.max():
                H_response[i, j] = 0
    return H_response


@jit(nopython=True)
def get_harris_matrix(I_x, I_y, w, i, j, win_height, win_width):
    """
    Returns the Harris matrix for the pixel at (i, j).
    """
    I_x_slice = I_x[
        i - win_height : i + win_height + 1, j - win_width : j + win_width + 1
    ]
    I_y_slice = I_y[
        i - win_height : i + win_height + 1, j - win_width : j + win_width + 1
    ]
    M_xx = np.sum(I_x_slice**2 * w)
    M_yy = np.sum(I_y_slice**2 * w)
    M_xy = np.sum(I_x_slice * I_y_slice * w)
    return np.array([[M_xx, M_xy], [M_xy, M_yy]])


@jit(nopython=True)
def get_cornerness(M, k):
    """
    Returns the cornerness of the Harris matrix.
    """
    return np.linalg.det(M) - k * np.trace(M) ** 2


# Read image
img = cv2.imread("./corners.png")

# Convert to gray
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
gray = gray.astype(np.float32) / gray.max()

# Compute Ix and Iy
sobel_x = np.array([[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]])
sobel_y = np.array([[-1, -2, -1], [0, 0, 0], [1, 2, 1]])

I_x = cv2.filter2D(gray, -1, sobel_x)
I_y = cv2.filter2D(gray, -1, sobel_y)

# Harris corner detection
kernel_size = 9
window_shape = (kernel_size, kernel_size)
win_height, win_width = (window_shape[0] - 1) // 2, (window_shape[1] - 1) // 2

w = get_gaussian_kernel(kernel_size)


H_response = np.zeros(gray.shape, dtype=np.float32)
k = 0.04

for i in range(win_height, gray.shape[0] - win_height):
    for j in range(win_width, gray.shape[1] - win_width):
        M = get_harris_matrix(I_x, I_y, w, i, j, win_height, win_width)
        H_response[i, j] = get_cornerness(M, k)

# Thresholding
# Empirically found values
threshold = 0.05 * H_response.max()
H_response[H_response < threshold] = 0


# Non-maximum suppression
H_response = non_max_suppression(H_response, win_height, win_width)

# Get corners
y_c, x_c = np.nonzero(H_response)

# Draw circles on the image
for i in range(len(x_c)):
    cv2.circle(img, (x_c[i], y_c[i]), 5, (0, 0, 255), -1)

# Save the image
cv2.imwrite("report/figs/task5/corners.png", img)

# Display the image with circles
cv2.imshow("Corners", img)
cv2.waitKey(0)
cv2.destroyAllWindows()
