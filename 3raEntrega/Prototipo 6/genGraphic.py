"""
Function that gets the first graphic
Args:
    totalCases (list): Saves the history of cases in integers
    totalDeaths (list): Saves the history of deaths in integers
    parts (list): List of the two titles of the graphic
    slices (list): Parts of the graphic
    colors (list): Colors that the graphic will use
    values (list): Values with which size is defined
Returns:
    The First Graphic
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

pyplot.clf()
parts = ('Cases', 'Deaths')
slices = (total, deaths)
colors = ('green', 'red')
values = (0.1, 0)
pyplot.rcParams['toolbar'] = 'None'
    
_, _, text = pyplot.pie(slices, colors = colors, labels = parts, autopct='%1.1f%%', explode=values, startangle = 90)
    
for tex in text:
    tex.set_color('white')
    
pyplot.ion()
pyplot.axis('equal')
pyplot.title('Graph of the data collected from the country')
pyplot.savefig('resources/Graphic.png', bbox_inches='tight')