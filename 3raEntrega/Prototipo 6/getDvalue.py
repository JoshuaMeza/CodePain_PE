"""
Function that gets the D value of the y=C*e^(Dx) equation
Args:
    totalDeaths (list): List with the history of deaths in integers
    count (int)= counts the number of values in totalDeaths
    x (int): summation of the x values (number of day)
    y (float): summation of the natural logarithm of the y values(number of deaths)
    sum1 (float): summation of the natural logarithm of the y values multiplied with the x values
    x2 (int): summation of the quadratic values of x
    n (int): last x value
    i (int): counter variable
Returns:
    The D value of the equation
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


count=len(totalDeaths)
x=0
y=0
sum1=0
x2=0
n=totalDeaths[count-1]
i=0
    
for i in range(count):
    sum1=math.log(totalDeaths[i])*i+sum1
    x=i+x
    y=math.log(totalDeaths[i])+y
    x2=i**2+x2
        
D=(n*(sum1)-x*y)/(n*x2-x**2)

return D