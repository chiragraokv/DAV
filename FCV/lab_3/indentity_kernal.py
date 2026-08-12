# apply idenity kernel given in manual page no 11
import cv2 as cv
import numpy as np
image = cv.imread(r"D:\aiml_b\FCV\lab_2\fruits.jpg")
kernel = [[0,0,0],
          [0,1,0],
          [0,0,0]]
image_idt = cv.filter2D(image,0,np.array(kernel))
cv.imshow("original",image)
cv.imshow("identity kernel",image_idt)
cv.waitKey(0)
cv.destroyAllWindows()