import cv2 as cv
import numpy as np

image = cv.imread(r"D:\aiml_b\FCV\lab_2\fruits.jpg")
blurred = cv.GaussianBlur(image, (3, 3), 2.0)
amount = 3
sub = image - blurred
sharpened = cv.addWeighted(image, amount, blurred, -amount, 0)
cv.imshow('sharpened_output.jpg', sharpened)
cv.imshow('edges',sub)
cv.imshow('blurred.jpg', blurred)
cv.waitKey(0)
cv.destroyAllWindows()