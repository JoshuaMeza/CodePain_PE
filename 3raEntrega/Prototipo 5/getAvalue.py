"""
Function that gets the A value of the y=A*e^(Bx) equation
Args:
    totalCases (list): List with the history of cases in integers
    count (int): counts the number of values in totalCases
    x (int): summation of the x values (number of day)
    y (float): summation of the natural logarithm of the y values(number of cases)
    sum1 (float): summation of the natural logarithm of the y values multiplied with the x values
    x2 (int): summation of the quadratic values of x
    n (int): last x value
    i (int): counter variable
Returns:
    The A value of the equation
"""

import http.client 
import json 
import math
from matplotlib import pyplot
import numpy as np
from math import exp
import shutil
from tkinter import * #Ignore warnings
from PIL import Image,ImageTk


count=len(totalCases)
x=0
y=0
sum1=0
x2=0
n=totalCases[count-1]
i=0
    
for i in range(count):
    sum1=math.log(totalCases[i])*i+sum1
    x=i+x
y=math.log(totalCases[i])+y
x2=i**2+x2
        
B=(n*(sum1)-x*y)/(n*x2-x**2)
A=(y/n)-B*(x/n)
A=2.7182818284590452**A

return A