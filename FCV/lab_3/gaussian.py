import cv2 as cv
import numpy as np

image = cv.imread(r"D:\aiml_b\FCV\lab_2\fruits.jpg")
blurred = cv.GaussianBlur(image, (9, 9), 2.0)
blurred = cv.GaussianBlur(blurred, (9, 9), 2.0)

cv.imshow('blurred.jpg', blurred)
cv.waitKey(0)
cv.destroyAllWindows()