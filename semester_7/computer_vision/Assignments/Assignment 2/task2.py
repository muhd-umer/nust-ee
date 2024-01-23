"""
Muhammad Umer
CMS IDs: 345834
Class: BEE-12

Task 2: Discover the methods of image stitching and stitch any two images.
"""

import cv2
import matplotlib.pyplot as plt
from colorama import Fore, Style

from task1 import *  # import the functions to extract keypoints and descriptors

plt.rcParams["font.family"] = "STIXGeneral"
import numpy as np

# Load the images
img1_path = "left.png"
img2_path = "right.png"
img1 = cv2.imread(img1_path)
img2 = cv2.imread(img2_path)

plt.imshow(img1[:, :, ::-1])
plt.tight_layout()
plt.savefig("report/figs/left.png", dpi=300, bbox_inches="tight", pad_inches=0)

plt.imshow(img2[:, :, ::-1])
plt.tight_layout()
plt.savefig("report/figs/right.png", dpi=300, bbox_inches="tight", pad_inches=0)

# Perform task1 on both images
img1_res, cv_img1_res = task1(img1_path, save=False)
img2_res, cv_img2_res = task1(img2_path, save=False)

# Extract keypoints and descriptors
kp1 = img1_res[0]
kp2 = img2_res[0]
descriptors1 = np.array(img1_res[1], dtype=np.float32)
descriptors2 = np.array(img2_res[1], dtype=np.float32)

# Set parameters for matching
ratio = 0.85
min_match = 10
smoothing_window_size = 200

# Perform matching
matcher = cv2.BFMatcher()
raw_matches = matcher.knnMatch(descriptors1, descriptors2, k=2)

# Filter matches
good_points = []
good_matches = []
for m1, m2 in raw_matches:
    if m1.distance < ratio * m2.distance:
        good_points.append((m1.trainIdx, m1.queryIdx))
        good_matches.append([m1])

# Find homography if enough matches
if len(good_points) > min_match:
    image1_kp = np.float32([kp1[i].pt for (_, i) in good_points])
    image2_kp = np.float32([kp2[i].pt for (i, _) in good_points])
    H, status = cv2.findHomography(image2_kp, image1_kp, cv2.RANSAC, 5.0)
else:
    raise AssertionError(
        Fore.RED
        + Style.BRIGHT
        + "Error: Not enough matches were found - %d/%d" % (len(good_points), min_match)
        + Style.RESET_ALL
    )


# Function to create a mask for blending
def create_mask(img1, img2, version):
    # Calculate dimensions
    height_img1 = img1.shape[0]
    width_img1 = img1.shape[1]
    width_img2 = img2.shape[1]
    height_panorama = height_img1
    width_panorama = width_img1 + width_img2
    offset = int(smoothing_window_size / 2)

    barrier = img1.shape[1] - int(smoothing_window_size / 2)
    mask = np.zeros((height_panorama, width_panorama))
    # Create mask
    if version == "left_image":
        mask[:, barrier - offset : barrier + offset] = np.tile(
            np.linspace(1, 0, 2 * offset).T, (height_panorama, 1)
        )
        mask[:, : barrier - offset] = 1
    else:
        mask[:, barrier - offset : barrier + offset] = np.tile(
            np.linspace(0, 1, 2 * offset).T, (height_panorama, 1)
        )
        mask[:, barrier + offset :] = 1
    return cv2.merge([mask, mask, mask])


# Calculate dimensions for panorama
height_img1 = img1.shape[0]
width_img1 = img1.shape[1]
width_img2 = img2.shape[1]
height_panorama = height_img1
width_panorama = width_img1 + width_img2

# Create panorama with left image
panorama1 = np.zeros((height_panorama, width_panorama, 3))
mask1 = create_mask(img1, img2, version="left_image")
panorama1[0 : img1.shape[0], 0 : img1.shape[1], :] = img1
panorama1 *= mask1

# Create panorama with right image
mask2 = create_mask(img1, img2, version="right_image")
panorama2 = cv2.warpPerspective(img2, H, (width_panorama, height_panorama)) * mask2

# Combine panoramas
result = panorama1 + panorama2

# Crop the result
rows, cols = np.where(result[:, :, 0] != 0)
min_row, max_row = min(rows), max(rows) + 1
min_col, max_col = min(cols), max(cols) + 1
final_result = result[min_row:max_row, min_col:max_col, :]

# Convert to uint8 and clip to range 0-255
panorama = np.clip(final_result, 0, 255).astype(np.uint8)

# Display and save the result
plt.imshow(panorama[:, :, ::-1])
plt.tight_layout()
plt.savefig("report/figs/stitched.png", dpi=300, bbox_inches="tight", pad_inches=0)
