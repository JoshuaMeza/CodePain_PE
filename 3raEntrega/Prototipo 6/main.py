"""
Author Joshua Meza, Jonathan Gómez, and Irving Poot
Date 11/05/2020
Version 1.3.1
    Changes:
        - Added visual interface.
Program who ask to the user a Country and returns the graphics of total cases and total deaths, the
total numbers and the logarithmic ecuations that represents the increase of cases and deaths.
    Special requirements:
        - Install the neccesary libraries (http.client,matplotlib,pillow) by using 'pip install <library>'.
        - Place the cmd on the 'Prototipo 5' folder before executing, the resources need it.
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

#Input
"""
Get the data from the API
Args:
    totalCases (list): Saves the history of cases in integers
    totalDeaths (list): Saves the history of deaths in integers
    code (string): Code of the country for the api
    codeL (tkinter): Selected option
    total (int): Stores the total amount of cases
    deaths (int): Stores the total amount of deaths
"""
totalCases=[]
totalDeaths=[]

codeL=listCountries.get(listCountries.curselection())
code=askCountry(codeL)
totalCases.extend(getCases(code))
totalDeaths.extend(getDeaths(code))
total = totalCases[0]
deaths = totalDeaths[0]

#Process
"""
Obtains the values of the variables of the exponential equations and generates the graphics
Args:
    total (int): Stores the total amount of cases
    deaths (int): Stores the total amount of deaths
    A (float): A value of the y=A*e^(Bx) equation
    B (float): B value of the y=A*e^(Bx) equation
    C (float): C value of the y=C*e^(Dx) equation
    D (float): D value of the y=C*e^(Dx) equation
"""
A=getAvalue(totalCases)
B=getBvalue(totalCases)
C=getCvalue(totalDeaths)
D=getDvalue(totalDeaths)

genGraphic(total, deaths)
genGraphic2(A, B, C, D)

#Output
"""
Return the list and equations
Args:
    total (int): Total amount of cases
    deaths (int): Total amount of deaths
    A (float): A value of the y=A*e^(Bx) equation
    B (float): B value of the y=A*e^(Bx) equation
    C (float): C value of the y=C*e^(Dx) equation
    D (float): D value of the y=C*e^(Dx) equation
    casesBox (tkinter): Box of confirmed cases
    deathBox (tkinter): Box of deaths
    eqCasBox (tkinter): Box of the cases equation
    eqDetBox (tkinter): Box of the deaths equation 
    load (PIL): Load the image
    render (PIL): Render the image
    table1 (PIL): Table of cases and deaths
    table2 (PIL): Table of equations
"""
casesBox.delete(0)
casesBox.insert(0,total)
eqCasBox.delete(0)
output=str("y= {}*e^({}*x)".format(A,B))
eqCasBox.insert(0,output)
deathBox.delete(0)
deathBox.insert(0,deaths)
eqDetBox.delete(0)
output=str("y= {}*e^({}*x)".format(C,D))
eqDetBox.insert(0,output)

load=Image.open('resources/Graphic.png')
load=load.resize((160, 160), Image.ANTIALIAS)
render=ImageTk.PhotoImage(load)
table1=Label(mid,image=render)
table1.image=render
table1.place(x=30,y=180)

load=Image.open('resources/Graphic2.png')
load=load.resize((160, 160), Image.ANTIALIAS)
render=ImageTk.PhotoImage(load)
table2=Label(mid,image=render)
table2.image=render
table2.place(x=265,y=180)

return 0