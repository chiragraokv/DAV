#5. Implement Canny edge detection algorithm. 
import cv2 as cv
import numpy as np
image = cv.imread(r"D:\aiml_b\FCV\lab_2\fruits.jpg")
edge = cv.Canny(image,2,2)

cv.imshow("canny",edge)
cv.waitKey(0)
cv.destroyAllWindows()