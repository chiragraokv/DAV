import cv2 as cv
import numpy as np

img = cv.imread(r'FCV\lab_2\fruits.jpg')

def pixelval(pix,r1,s1,r2,s2):
    if(0<=pix and pix <=r1):
        return (s1/r1)*pix
    elif(r1 < pix and pix <=r2):
        return ((s2-s1)/(r2-r1)) * (pix - r1) + s1
    else:
        return ((255-s2)/(255-s1)) * (pix-r2) + s2
    
r1 = 100
s1=0
r2 = 150
s2 = 255

pixelval_vec = np.vectorize(pixelval)
contrast_streached = pixelval_vec(img,r1,s1,r2,s2)
cv.imwrite(r'FCV\lab_2\piece.png',contrast_streached)