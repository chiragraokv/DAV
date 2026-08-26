import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt
image = cv.imread(r"D:\aiml_b\FCV\cat.jpg")
gray = cv.cvtColor(image, cv.COLOR_BGR2GRAY)
gray = cv.GaussianBlur(gray, (3, 3), 0)
thresh_mean = cv.adaptiveThreshold(gray, maxValue=255, adaptiveMethod=cv.ADAPTIVE_THRESH_MEAN_C, thresholdType=cv.THRESH_BINARY, blockSize=11, C=2            )
thresh_gaussian = cv.adaptiveThreshold(gray, maxValue=255, adaptiveMethod=cv.ADAPTIVE_THRESH_GAUSSIAN_C, thresholdType=cv.THRESH_BINARY, blockSize=11, C=2)
images = [gray, thresh_mean, thresh_gaussian]
tags = ["Grayscale Input", "Adaptive Mean", "Adaptive Gaussian"]
plt.figure(figsize=(12, 4))
for i in range(len(images)):
    plt.subplot(1, 3, 1 + i)
    im = images[i]
    # If single channel, show using gray colormap
    plt.imshow(im, cmap='gray')
    plt.title(tags[i])
    plt.axis("off")

plt.tight_layout()
plt.show()