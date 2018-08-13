import cv2, numpy, time
def mhello():
    print "hellogy"
def detect_face(video_full_path):
    print video_full_path
    faceCascade = cv2.CascadeClassifier('C:/Users/daisy/Desktop/facedet/haarcascade_frontalface_default.xml')
    out = cv2.VideoWriter('C:/Users/daisy/Desktop/facedet/output.avi',-1, 20.0, (2160,1080))
    capInput  = cv2.VideoCapture(video_full_path)
    nextCaptureTime = time.time()
    if not capInput.isOpened():
        print('Capture failed because of camera')
    timeF = 5
    c=1

    while 1:
        ret, img = capInput.read()
        if(c%timeF == 0):
            gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
            faces = faceCascade.detectMultiScale(gray, 1.3, 5)
            for x, y, w, h in faces:
                img = cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 2)
            cv2.imshow('FaceDetect', img)   
            out.write(img)
        c=c+1
        if cv2.waitKey(1) & 0xFF == 27: break
        if not ret:break
    capInput.release()
    out.release()
    cv2.destroyAllWindows()
