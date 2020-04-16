from tkinter import *
import tkinter.font
from gpiozero import LED
import RPi.GPIO as GPIO

redLED = LED(17)
greenLED = LED(18)
blueLED = LED(27)

win = Tk()
win.title("Radio Button LEDs")
myFont = tkinter.font.Font(family="Ariel", size = 12, weight="bold")
val = IntVar()

def toggleLEDs():
	var =val.get()
	if var == 1:
		redLED.on()
		greenLED.off()
		blueLED.off()
	elif var == 2:
		redLED.off()
		greenLED.on()
		blueLED.off()
	else:
		redLED.off()
		greenLED.off()
		blueLED.on()

def close():
	GPIO.cleanup()
	win.destroy()


redB = Radiobutton( win, text = "RED LED", font = myFont , variable = val , value = 1,command = toggleLEDs,bg = "pink",height = 1, width = 8) 
redB.grid(row=1 , column = 0)

greenB = Radiobutton( win, text = "GREEN LED", font = myFont , variable = val , value = 2,command = toggleLEDs,bg = "cyan", height = 1 ,width = 8)
greenB.grid(row=1 , column = 1)

blueB = Radiobutton( win, text = "BLUE LED", font = myFont , variable = val , value = 3,command = toggleLEDs,bg = "sky blue" , height = 1 , width = 8)
blueB.grid(row=1 , column = 2)

closeB = Button( win, text = "EXIT", font = myFont , command = close ,bg = "orange" , height = 1 , width = 5)
closeB.grid(row=2 , column = 1)

win.protocol("WM_DELETE_WINDOW")
win.mainloop()
