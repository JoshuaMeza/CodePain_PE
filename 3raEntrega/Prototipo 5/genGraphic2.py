"""
Function that gets the first graphic
Args:
    e (int): Stores the euler value
    f (int): Stores the first ecuation
    g (int): Stores the second ecuation
    v (Lista): Stores the limits of the graphic
    x (int): Stores the cases to use
Returns:
    The Second Graphic
"""
import http.client 
import json 
import math
from matplotlib import pyplot
import numpy as np
from math import exp
import shutil
from tkinter import * #Ignore warnings

pyplot.clf()
e = exp(1)
f = lambda x: A*(e**(B*x))

g= lambda x: C*(e**(D*x))
v = [-25, 25, 0, 25]
x =np.linspace(-25,25,100)
pyplot.ion()
pyplot.rcParams['toolbar'] = 'None'
pyplot.plot(x,f(x),'g',label='Cases')
pyplot.plot(x,g(x),'r', label='Deaths')
pyplot.xlabel('Time')
pyplot.ylabel('Amount')
pyplot.title('Future forecast')
pyplot.legend()
pyplot.axis(v)
pyplot.grid()
pyplot.savefig('resources/Graphic2.png', bbox_inches='tight')