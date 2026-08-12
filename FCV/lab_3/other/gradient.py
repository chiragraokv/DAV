import cv2 as cv
import numpy as np
image = cv.imread(r"D:\aiml_b\FCV\lab_2\fruits.jpg")
sobel_x = cv.Sobel(image, cv.CV_64F, 1, 0, ksize=3)
sobel_y = cv.Sobel(image, cv.CV_64F, 0, 1, ksize=3)
magnitude = np.sqrt(sobel_x**2 + sobel_y**2)
print("\nGradient Magnitude:")
cv.imshow("sobel_y",sobel_y)
cv.imshow("sobel_x",sobel_x)
cv.waitKey(0)
cv.destroyAllWindows()