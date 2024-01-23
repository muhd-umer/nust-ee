"""
Muhammad Umer, Muhammad Ahmed Mohsin, Muhammad Saad
CMS IDs: 345834, 333060, 333414
Class: BEE-12

Task 1: Take any image and perform Gaussian filtering, box filtering and median filtering. Also provide comments on the results.
"""

import cv2
import numpy as np


def get_gaussian_kernel(size, sigma: float = -1):
    """
    Generates a Gaussian kernel of the specified size and sigma.

    If sigma = -1, then sigma is automatically calculated as (size - 1) / 6.0,
    as per the OpenCV documentation.
    """
    if sigma < 0:
        sigma = (size - 1) / 6.0

    # Generate a grid using the specified size
    axis = np.linspace(-(size - 1) / 2.0, (size - 1) / 2.0, size)
    x, y = np.meshgrid(axis, axis)

    # Create the kernel
    gaussian_kernel = np.exp(-0.5 * (x**2 + y**2) / sigma**2)

    return gaussian_kernel / np.sum(gaussian_kernel)


# Read image
img = cv2.imread("./lenna_noisy.png")

# Define kernel size
kernel_size = 7

# Define kernels
box_kernel = (1 / kernel_size**2) * np.ones((kernel_size, kernel_size))
gaussian_kernel = get_gaussian_kernel(kernel_size, 1.2)  # empirically determined

# Apply filters
box_filtered = cv2.filter2D(img, -1, box_kernel)
gaussian_filtered = cv2.filter2D(img, -1, gaussian_kernel)
median_filtered = cv2.medianBlur(img, kernel_size)

# Save images
cv2.imwrite("report/figs/task1/box_filtered.png", box_filtered)
cv2.imwrite("report/figs/task1/gaussian_filtered.png", gaussian_filtered)
cv2.imwrite("report/figs/task1/median_filtered.png", median_filtered)

# Show images
cv2.imshow("Original", img)
cv2.imshow("Box Filtered", box_filtered)
cv2.imshow("Gaussian Filtered", gaussian_filtered)
cv2.imshow("Median Filtered", median_filtered)

cv2.waitKey(0)
cv2.destroyAllWindows()
