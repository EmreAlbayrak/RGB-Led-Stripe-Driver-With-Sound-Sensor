# -*- coding: utf-8 -*-
"""
Created on Wed Apr 24 10:12:02 2019

@author: Emre
"""

import serial
import time

ser: object = serial.Serial('COM17', baudrate = 9600, timeout=0)


def serialcolour():
    colourinput = input('\nPick a colour : \n1 ==========> red\n2 ==========> green\n3 ==========> blue\n4 ==========> yellow\n5 ==========> orange\n6 ==========> purple\n7 ==========> sky blue\n8 ==========> white\n============> ')
    if colourinput == '1':
        print('\nColour changed! New colour ===> red')
        ser.write(b'c1')
    elif colourinput == '2':
        print('\nColour changed! New colour ===> green')
        ser.write(b'c2')
    elif colourinput == '3':
        print('\nColour changed! New colour ===> blue')
        ser.write(b'c3')
    elif colourinput == '4':
        print('\nColour changed! New colour ===> yellow')
        ser.write(b'c4')
    elif colourinput == '5':
        print('\nColour changed! New colour ===> orange')
        ser.write(b'c5')
    elif colourinput == '6':
        print('\nColour changed! New colour ===> purple')
        ser.write(b'c6')
    elif colourinput == '7':
        print('\nColour changed! New colour ===> sky blue')
        ser.write(b'c7')
    elif colourinput == '8':
        print('\nColour changed! New colour ===> white')
        ser.write(b'c8')
    else:
        print('Please enter an valid option!')
        time.sleep(2)
        serialcolour()
    time.sleep(2)
    againmenu()
    
def serialpeak():
    print('\nEnter new peak limit (between 1-9) ==> ')
    peakinput = input()
    ser.write(b'p')
    print('\nPeak level changed! New peak level ===> ',peakinput)
    time.sleep(2)
    againmenu()
    
def mainmenu():
    option = input('\nHello Emre! Welcome again to RGB serial software!\nWhich one do you want to change ? Colour or peak level? (c/p) ==> ')
    if option == 'c':
        serialcolour()
    elif option == 'p':
        serialpeak()
    else:
        print('Please enter a valid option!')
        mainmenu()

def againmenu():
    again = input('\nWant to change again? (y/n)')
    if again == 'y':
        mainmenu()
    elif again == 'n':
        print('\nJust enjoy! See you next time... Copyright Emre Albayrak ©')
        time.sleep(2)
    else:
        print('\nPlease enter a valid option!')
        time.sleep(1)
        againmenu()
        
#Main loop starts here

mainmenu()