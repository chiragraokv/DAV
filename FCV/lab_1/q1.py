import cv2 as cv
# write a simple program to read, display and write an image
image = cv.imread(r"D:\aiml_b\lab_1\image.jpg")
grey = cv.cvtColor(image,cv.COLOR_BGR2GRAY)
cv.imshow('display',grey)
cv.imwrite(r"D:\aiml_b\lab_1\saved.png",grey)
cv.waitKey(0)
cv.destroyAllWindows()
