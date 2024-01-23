"""
Muhammad Umer, Muhammad Ahmed Mohsin, Muhammad Saad
CMS IDs: 345834, 333060, 333414
Class: BEE-12

Task 4: Take a colored image and provide its gray and binary representation.
"""

import cv2


def rgb2gray(rgb):
    """Convert RGB image to grayscale

    Standard formula for converting RGB to grayscale
    Reference: https://en.wikipedia.org/wiki/Grayscale#Converting_color_to_grayscale
    """

    # Get the red, green, and blue channels of the image
    red_channel = rgb[:, :, 0]
    green_channel = rgb[:, :, 1]
    blue_channel = rgb[:, :, 2]

    # Calculate the grayscale value for each pixel using the standard formula
    gray = 0.2989 * red_channel + 0.5870 * green_channel + 0.1140 * blue_channel

    return gray


# Read image
img = cv2.imread("./lenna.png")

# Convert to gray
gray = rgb2gray(img)  # divide by 255 to normalize
norm_gray = gray / 255

# Convert to binary
threshold = 127  # empirically found
binary = gray.copy()
binary[binary < threshold] = 0
binary[binary >= threshold] = 255

# Save images
cv2.imwrite("report/figs/task4/gray.png", gray)
cv2.imwrite("report/figs/task4/binary.png", binary)

# Show images
cv2.imshow("Original", img)
cv2.imshow("Gray", norm_gray)
cv2.imshow("Binary", binary)
cv2.waitKey(0)
cv2.destroyAllWindows()
