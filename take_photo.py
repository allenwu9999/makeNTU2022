import picamera
import time
import RPi.GPIO as GPIO
import cv2


def func(img):
    img = cv2.resize(img, dsize=(200, int(
        200 * img.shape[0]*1.8 / img.shape[1])), interpolation=cv2.INTER_CUBIC)
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    circles = cv2.HoughCircles(gray, cv2.HOUGH_GRADIENT, 1,
                               100, param1=100, param2=50, minRadius=20, maxRadius=80)
    for circle in circles[0]:
        x = int(circle[0])
        y = int(circle[1])
        r = int(circle[2])
        img = cv2.circle(img, (x, y), r, (0, 0, 255), -1)
        break
    #cv2.waitKey(0)
    #cv2.destroyAllWindows()
    return r

L_pin = 4 #30
M_pin = 27 #28
R_pin = 22 #26
# The dish is placed on the table
# control_cam_pin = 10
camera = picamera.PiCamera()
GPIO.setmode(GPIO.BCM)
GPIO.setup(L_pin, GPIO.OUT)
GPIO.setup(R_pin, GPIO.OUT)
GPIO.setup(M_pin, GPIO.OUT)
GPIO.output(L_pin, 0)
GPIO.output(R_pin, 0)
GPIO.output(M_pin, 0)
while(1):
    camera.capture("goal.jpg")
    jpg = cv2.imread("goal.jpg")
    jpg = cv2.flip(jpg,-1)
    cv2.imwrite("goal.jpg", jpg)
    try:
        val = func(jpg)
        print("ff")
    except:
        val=-1
        print("ee")
    if(val >= 40):
        GPIO.output(L_pin,GPIO.HIGH)
        GPIO.output(R_pin, 0)
        GPIO.output(M_pin, 0)
        print("L")
        time.sleep(2)
    elif(val<40 and val>=32):
        GPIO.output(M_pin,GPIO.HIGH)
        GPIO.output(L_pin, 0)
        GPIO.output(R_pin, 0)
        print("M")
        time.sleep(2)
    elif(val<32 and val>0):
        GPIO.output(R_pin,GPIO.HIGH)
        GPIO.output(L_pin, 0)
        GPIO.output(M_pin, 0)
        print("R")
        time.sleep(2)
    time.sleep(2)
    print("val:")
    print(val)
cv2.waitKey(0)
cv2.destroyAllWindows()
