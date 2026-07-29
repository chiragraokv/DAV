import cv2 as cv
#write a simple programme to read and write vid file
vid = cv.VideoCapture(r'lab_1\stock_footage.mp4')
if not vid.isOpened():
    print(f"Error: Cannot open video source:")
    exit
print(f"frames :{vid.get(5)} total frames = {vid.get(7)} duration : {vid.get(7)/vid.get(5)} sec")

width = int(vid.get(cv.CAP_PROP_FRAME_WIDTH))
height = int(vid.get(cv.CAP_PROP_FRAME_HEIGHT))
fps = vid.get(cv.CAP_PROP_FPS)
print(fps)
out = cv.VideoWriter(
    "output.mp4",
    cv.VideoWriter_fourcc(*'mp4v'),
    300,
    (800, 450)
)
while True:
   ret, frame = vid.read()
   if not ret: 
       break
   frame = cv.resize(frame, (450, 800))
   cv.imshow("Video", frame)
   gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
   gray = cv.cvtColor(gray, cv.COLOR_GRAY2BGR)  # Convert back to 3 channels
   gray = cv.rotate(gray,cv.ROTATE_90_CLOCKWISE)
   out.write(gray)
   if cv.waitKey(25) & 0xFF == ord('q'):
       break
vid.release()
out.release()
cv.destroyAllWindows()