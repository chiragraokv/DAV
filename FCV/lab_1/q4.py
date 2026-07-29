import cv2 as cv
import numpy as np
import random
# write a simple program extract rgb values of pixels
image = cv.imread(r"D:\aiml_b\lab_1\image.jpg")
(h,w,c) = image.shape
for i in range(2):
    x1 = random.randint(0, w-1)
    y1 = random.randint(0, h-1)

    x2 = random.randint(0, w-1)
    y2 = random.randint(0, h-1)
    colour = (random.randint(0,255),random.randint(0,255),random.randint(0,255))
    colour2 = (random.randint(0,255),random.randint(0,255),random.randint(100,255))
    image = cv.rectangle(image,(x1,y1),(x2,y2),colour,thickness=random.randint(4,10))
    image = cv.circle(image,(x1,y2),radius=random.randint(0,h),color= colour,thickness=random.randint(4,10))
cv.imwrite(r"D:\aiml_b\lab_1\rectangle1.png",image)
cv.waitKey(0)
cv.destroyAllWindows()