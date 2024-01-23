"""
Muhammad Umer, Muhammad Ahmed Mohsin, Muhammad Saad
CMS IDs: 345834, 333060, 333414
Class: BEE-12

Task 3: Take any image and plot its histogram representation.
"""


import cv2
import matplotlib.pyplot as plt
import numpy as np


def compute_histogram(img):
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    rows, cols = gray.shape

    hist = np.zeros(256)

    # Iterate over image and increment histogram
    for i in range(rows):
        for j in range(cols):
            hist[gray[i, j]] += 1

    return hist


plt.rcParams["mathtext.fontset"] = "stix"
plt.rcParams["font.family"] = "STIXGeneral"

# Read image
img = cv2.imread("./lenna.png")

# Compute histogram
hist = compute_histogram(img)

# Plot and histogram
plt.figure(figsize=(12, 6))
bars = plt.bar(np.arange(256), hist, color="red", edgecolor="black")
plt.xlabel("Pixel Intensity", fontsize=16)
plt.ylabel("Frequency", fontsize=16)
plt.xticks(fontsize=16)
plt.yticks(fontsize=16)
plt.xlim(0, 256)
plt.grid(alpha=0.5)
plt.legend([bars], ["Pixel Intensity"], fontsize=16)
plt.tight_layout()
plt.savefig("report/figs/task3/histogram.png", dpi=300)
plt.show()
