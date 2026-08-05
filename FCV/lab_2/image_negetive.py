import cv2 as cv
image = cv.imread(r'FCV\lab_2\fruits.jpg')
negetive = cv.bitwise_not(image)
cv.imwrite(r'FCV\lab_2\negetive.png',negetive)