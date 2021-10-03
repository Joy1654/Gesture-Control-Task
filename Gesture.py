import serial  # Serial imported for Serial communication
import time  # Required to use delay functions
import pyautogui

ArduinoSerial = serial.Serial('com4', 9600)  # Create Serial port object // 
time.sleep(5)  # wait for 5 seconds for the communication to get

while True:
    Check = str(ArduinoSerial.readline())  # reading  the serial data Input
    print(Check)

    if 'Start/Stop' in Check:
        pyautogui.typewrite(['space'], 0.2)
    if 'Backward' in Check:
        pyautogui.typewrite(['j'], 0.2)
    if 'Forward' in Check:
        pyautogui.typewrite(['l'], 0.2)
    if 'Volumeup' in Check:
        pyautogui.hotkey('shift', 'up')
    if 'Volumedown' in Check:
        pyautogui.hotkey('shift', 'down')
    if'PrintScreen' in Check:
        pyautogui.hotkey('win', 'prtsc')
    Check = ""
