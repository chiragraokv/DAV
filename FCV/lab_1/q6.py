import cv2 as cv
# write a simple programme to rotate an image
image = cv.imread(r"D:\aiml_b\lab_1\image.jpg")
grey = cv.cvtColor(image,cv.COLOR_BGR2GRAY)
cv.imshow('display',cv.rotate(grey,cv.ROTATE_90_CLOCKWISE))
cv.waitKey(0)
cv.destroyAllWindows()
