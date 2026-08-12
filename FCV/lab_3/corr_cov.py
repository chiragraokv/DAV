# werite a program to compute convolution and correlation 
#imag neighbourhood = [10 20 30; 40 45 50; 50 55 60] - input image
#using kernel = p[1 2 3; 4 5 6; 7 8 9]
import cv2 as cv
import numpy as np
image = np.array([[10,20,30], [40,45,50],[50,55,60]],dtype=np.float32)
kernel = np.array([[1,2,3],[4,5,6],[7,8,9]],dtype=np.float32)
corr = np.sum(image * kernel)
k_flip = np.flip(kernel)
conv = np.sum(image*k_flip)
print(f"correlation: {corr}")
print(f"convolution: {conv}")
#output
#correlation: 2155.0
# convolution: 1445.0