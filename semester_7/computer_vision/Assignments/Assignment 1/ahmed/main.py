import cv2
import matplotlib.pyplot as plt
import numpy as np


# Define a function to generate a Gaussian kernel
def generate_gaussian_kernel(size=5, sigma=5):
    axis = np.linspace(-(size - 1) / 2.0, (size - 1) / 2.0, size)
    x, y = np.meshgrid(axis, axis)

    gaussian_kernel = np.exp(-0.5 * (np.square(x) + np.square(y)) / np.square(sigma))

    return gaussian_kernel / np.sum(gaussian_kernel)


# Load the image
image = cv2.imread("image.jpeg")

# Convert the image to grayscale
gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Generate a Gaussian kernel
kernel_size = 5
sigma = 15
gaussian_kernel = generate_gaussian_kernel(kernel_size, sigma)

# Apply the Gaussian filter
filtered_image = cv2.filter2D(gray_image, -1, gaussian_kernel)

# Convert the filtered image back to RGB
filtered_image_rgb = cv2.cvtColor(filtered_image, cv2.COLOR_GRAY2RGB)

# Print the kernel
print("Gaussian Kernel: ", gaussian_kernel)

# Display and save the results
cv2.imshow("Original Image", image)
cv2.imshow("Gaussian Blur", filtered_image_rgb)
cv2.waitKey(0)
cv2.destroyAllWindows()


# Define a function to apply box blur to an image
def box_blur(image, kernel_size):
    height, width = image.shape
    kernel = np.ones((kernel_size, kernel_size), np.float32) / (kernel_size**2)

    result = np.zeros((height, width), dtype=np.uint8)

    half_kernel = kernel_size // 2

    for y in range(half_kernel, height - half_kernel):
        for x in range(half_kernel, width - half_kernel):
            # Apply the kernel to the neighborhood
            neighborhood = image[
                y - half_kernel : y + half_kernel + 1,
                x - half_kernel : x + half_kernel + 1,
            ]
            weighted_sum = np.sum(neighborhood * kernel)
            result[y, x] = int(weighted_sum)

    return result


# Apply box blur to the image
image = cv2.imread("image.jpeg", cv2.IMREAD_GRAYSCALE)
kernel_size = 5
blurred_image = box_blur(image, kernel_size)

# Display and save the results
cv2.imshow("Original Image", image)
cv2.imshow("Box Blur", blurred_image)
cv2.waitKey(0)
cv2.destroyAllWindows()


# Define a function to apply median filter to an image
def median_filter(image, kernel_size):
    return cv2.medianBlur(image, kernel_size)


# Apply median filter to the image
image = cv2.imread("image.jpeg", cv2.IMREAD_GRAYSCALE)
kernel_size = 5
filtered_image = median_filter(image, kernel_size)

# Display and save the results
cv2.imshow("Original Image", image)
cv2.imshow("Median Filter", filtered_image)
cv2.waitKey(0)
cv2.destroyAllWindows()


# Define a function to apply Prewitt filter to an image
def prewitt_filter(image):
    # Define a Prewitt kernel
    kernel_x = np.array([[-1, 0, 1], [-1, 0, 1], [-1, 0, 1]])
    kernel_y = np.array([[-1, -1, -1], [0, 0, 0], [1, 1, 1]])

    # Apply the kernels to the image and add the images
    prewitt_x = cv2.filter2D(image, -1, kernel_x)
    prewitt_y = cv2.filter2D(image, -1, kernel_y)

    return prewitt_x, prewitt_y


# Apply Prewitt filter to the image
image = cv2.imread("image.jpeg", cv2.IMREAD_GRAYSCALE)
prewitt_x, prewitt_y = prewitt_filter(image)

# Display and save the results
cv2.imshow("Original Image", image)
cv2.imshow("Prewitt X", prewitt_x)
cv2.imshow("Prewitt Y", prewitt_y)
cv2.waitKey(0)
cv2.destroyAllWindows()


# Define a function to apply Sobel filter to an image
def sobel_filter(image):
    # Define a Sobel kernel
    kernel_x = np.array([[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]])
    kernel_y = np.array([[-1, -2, -1], [0, 0, 0], [1, 2, 1]])

    # Apply the kernels to the image and add the images
    sobel_x = cv2.filter2D(image, -1, kernel_x)
    sobel_y = cv2.filter2D(image, -1, kernel_y)

    return sobel_x, sobel_y


# Apply Sobel filter to the image
image = cv2.imread("image.jpeg", cv2.IMREAD_GRAYSCALE)
sobel_x, sobel_y = sobel_filter(image)

# Display and save the results
cv2.imshow("Original Image", image)
cv2.imshow("Sobel X", sobel_x)
cv2.imshow("Sobel Y", sobel_y)
cv2.waitKey(0)
cv2.destroyAllWindows()


# Load the image in grayscale
img = cv2.imread("image.jpeg", 0)

# Calculate the histogram
hist = cv2.calcHist([img], [0], None, [256], [0, 256])

# Create a figure and axis
fig, ax = plt.subplots()

# Customize the plot
ax.plot(hist, color="black")
ax.fill_between(range(256), hist.flatten(), 0, color="red", alpha=0.6)
ax.set_xlim(0, 256)
ax.set_ylim(0, max(hist) + 1000)
ax.set_xlabel("Pixel Value")
ax.set_ylabel("Frequency")
ax.set_title("Image Histogram")
ax.grid(True)

# Show the plot
plt.show()


# Load a colored image
image = cv2.imread("image.jpg")

# Convert the image to grayscale
gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Apply thresholding to create a binary image
_, binary_image = cv2.threshold(gray_image, 128, 255, cv2.THRESH_BINARY)

# Display the original, grayscale, and binary images
cv2.imshow("Original Image", image)
cv2.imshow("Grayscale Image", gray_image)
cv2.imshow("Binary Image", binary_image)

cv2.waitKey(0)
cv2.destroyAllWindows()


# Define a function to detect corners using Harris corner detection
def harris_corner_detection(image):
    # Convert the image to grayscale
    gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # Apply Harris corner detection
    corners = cv2.cornerHarris(gray_image, 2, 3, 0.04)

    # Threshold the corners
    corners[corners < 0.01 * corners.max()] = 0

    # Draw circles around the corners
    radius = 5
    thickness = 2
    color = (0, 0, 255)
    for i in range(corners.shape[0]):
        for j in range(corners.shape[1]):
            if corners[i, j] > 0:
                center = (j, i)
                cv2.circle(image, center, radius, color, thickness)

    return image


# Load an image
image = cv2.imread("image.jpeg")

# Detect corners using Harris corner detection
corners_image = harris_corner_detection(image)

# Display and save the results
cv2.imshow("Original Image", image)
cv2.imshow("Corners", corners_image)
cv2.waitKey(0)
cv2.destroyAllWindows()
