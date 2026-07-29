import cv2 as cv
import numpy as np
# write a simple program extract rgb values of pixels
image = cv.imread(r"D:\aiml_b\lab_1\image.jpg")
print(image.shape)
print(f"Blue: {image[:,:,0]}\n Green {image[:,:,1]},\nRed: {image[:,:,2]}")
zeros= np.zeros_like(image[:,:,0])
red = cv.merge([zeros,zeros,image[:,:,2]])
green = cv.merge([zeros,image[:,:,1],zeros])
blue = cv.merge([image[:,:,0],zeros,zeros])
cv.imwrite("play.png",cv.merge([image[:,:,1],image[:,:,2],image[:,:,0]]))
cv.imshow("red",red)
cv.imshow("green",green)
cv.imshow("blue",blue)
cv.waitKey(0)
cv.destroyAllWindows()