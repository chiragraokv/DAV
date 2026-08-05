import cv2 as cv
import numpy as np
img = cv.imread(r'D:\aiml_b\FCV\lab_2\fruits.jpg')
img = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
c =  255/(np.log(1+np.max(img)))
log_tr = c * np.log(1+img)
log_tr = np.array(log_tr,dtype=np.uint8)
cv.imwrite(r'D:\aiml_b\FCV\lab_2\log.png',log_tr)
cv.waitKey(0)
cv.destroyAllWindows()