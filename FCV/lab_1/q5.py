import cv2 as cv
# write a programme to resize an image
image = cv.imread(r"D:\aiml_b\lab_1\image.jpg")
cv.imshow('display',cv.resize(cv.cvtColor(image,cv.COLOR_BGR2RGB),(300,300),interpolation=4))
cv.waitKey(0)
cv.destroyAllWindows()
