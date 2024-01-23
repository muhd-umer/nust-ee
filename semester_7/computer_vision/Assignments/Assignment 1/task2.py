"""
Muhammad Umer, Muhammad Ahmed Mohsin, Muhammad Saad
CMS IDs: 345834, 333060, 333414
Class: BEE-12

Task 2: Take any image and detect edges by using Sobel and Prewitt Kernel. Comment on both results
"""

import cv2
import numpy as np

# Read image
img = cv2.imread("./lenna.png")

# Convert to gray
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# Define kernels
sobel_x = np.array([[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]])
sobel_y = np.array([[-1, -2, -1], [0, 0, 0], [1, 2, 1]])

prewitt_x = np.array([[-1, 0, 1], [-1, 0, 1], [-1, 0, 1]])
prewitt_y = np.array([[-1, -1, -1], [0, 0, 0], [1, 1, 1]])

# Apply filters
sobel_x_filtered = cv2.filter2D(gray, -1, sobel_x)
sobel_y_filtered = cv2.filter2D(gray, -1, sobel_y)

prewitt_x_filtered = cv2.filter2D(gray, -1, prewitt_x)
prewitt_y_filtered = cv2.filter2D(gray, -1, prewitt_y)

# Save images
cv2.imwrite("report/figs/task2/sobel_x_filtered.png", sobel_x_filtered)
cv2.imwrite("report/figs/task2/sobel_y_filtered.png", sobel_y_filtered)
cv2.imwrite("report/figs/task2/prewitt_x_filtered.png", prewitt_x_filtered)
cv2.imwrite("report/figs/task2/prewitt_y_filtered.png", prewitt_y_filtered)

# Show images
cv2.imshow("Original", img)
cv2.imshow("Sobel X Filtered", sobel_x_filtered)
cv2.imshow("Sobel Y Filtered", sobel_y_filtered)
cv2.imshow("Prewitt X Filtered", prewitt_x_filtered)
cv2.imshow("Prewitt Y Filtered", prewitt_y_filtered)
cv2.waitKey(0)
cv2.destroyAllWindows()
