import cv2 as cv
import numpy as np
img = cv.imread(r'D:\aiml_b\FCV\lab_2\fruits.jpg')
for gamma in [2.2,3,5,10,20]:
    gamma_corrected= np.array(255*(img/255)**gamma)
    cv.imshow(f"Gamma:{gamma}",gamma_corrected)
    cv.imwrite(f'D:\\aiml_b\\FCV\\lab_2\\gamma_{gamma}.png',gamma_corrected)
    print(gamma_corrected<1)
    cv.waitKey(0)
    cv.destroyAllWindows()