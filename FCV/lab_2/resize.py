import cv2 as cv
img = cv.imread(r'FCV\lab_2\fruits.jpg')
cv.imwrite(r'FCV\lab_2\rotate.png',cv.resize(img[:400,:300,:],(100,200)))