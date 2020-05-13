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

"""
Instruction to inicialize the program, contains the visual aspect to avoid errors
Args:
    root (tkinter): Visual root
    codeL (tkinter): Function that saves like string the user's selection
    imgIcon (tkinter): References the custom icon of the app
    top (tkinter): Top frame
    mid (tkinter): Middle frame
    bot (tkinter): Bottom frame
    listCountries (tkinter): Box with countries
    casesBox (tkinter): Box of confrimed cases
    deathBox (tkinter): Box of deaths
    eqCasBox (tkinter): Box of the cases equation
    eqDetBox (tkinter): Box of the deaths equation
    scrollbarCas (tkinter): Scrollbar of the box of confirmed cases
    scrollbarDet (tkinter): Scrollbar of the box of deaths
    load (PIL): Load the image
    render (PIL): Render the image
    table1 (PIL): Table of cases and deaths
    table2 (PIL): Table of equations
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

if __name__=='__main__':

    #Visual Aspect
    root=Tk()
    codeL=StringVar()

    root.title("Coronavirus Graphics")
    root.geometry("465x450")

    imgIcon = PhotoImage(file='resources/Icon.gif')
    root.tk.call('wm','iconphoto', root._w, imgIcon)
    root.resizable(0, 0)

    top=Frame(root,width=465,height=50)
    top.pack(anchor="n")
    top.config(bg="#AEE8D7")

    mid=Frame(root,width=465,height=370)
    mid.pack(anchor="center")
    mid.config(bg="white")
    
    scrollbarCas=Scrollbar(mid)
    scrollbarDet=Scrollbar(mid)

    bot=Frame(root,width=465,height=30)
    bot.pack(anchor="s")
    bot.config(bg="#D5D7D3")

    Label(top,text="Welcome! To see a graphic select the country and press 'Submit'.",font=('bold',12),justify="center",bg="#AEE8D7").place(x=6,y=12)
    Label(mid,text="Avaliable countries:",font=('bold',10),justify="left",bg="white").place(x=15,y=40)
    Label(bot,text="Property of Code-Pain Team",font=('bold',8),justify="left",bg="#D5D7D3").place(x=0,y=6)

    listCountries=Listbox(mid, height=3, highlightcolor="blue")
    listCountries.insert(1, "Mexico")
    listCountries.insert(2, "United States")
    listCountries.insert(3, "Canada")
    listCountries.place(x=140,y=26)

    Button(mid,text="Submit",justify="center",activebackground="blue",command=main).place(x=300,y=40)

    Label(mid,text="Confirmed cases:",font=('bold',10),justify="left",bg="white").place(x=15,y=90)
    casesBox=Listbox(mid,width=15,height=1)
    casesBox.place(x=130,y=90)

    Label(mid,text="Cases equation:",font=('bold',10),justify="left",bg="white").place(x=15,y=115)
    eqCasBox=Listbox(mid,width=15,height=1,xscrollcommand=scrollbarCas.set)
    eqCasBox.place(x=130,y=115)

    Label(mid,text="Actual deaths:",font=('bold',10),justify="left",bg="white").place(x=230,y=90)
    deathBox=Listbox(mid,width=15,height=1)
    deathBox.place(x=335,y=90)

    Label(mid,text="Deaths equation:",font=('bold',10),justify="left",bg="white").place(x=230,y=115)
    eqDetBox=Listbox(mid,width=15,height=1,xscrollcommand=scrollbarDet.set)
    eqDetBox.place(x=335,y=115)

    scrollbarCas.place(x=130,y=140,width=94)
    scrollbarCas.config(command=eqCasBox.xview,orient=HORIZONTAL)

    scrollbarDet.place(x=335,y=140,width=94)
    scrollbarDet.config(command=eqDetBox.xview,orient=HORIZONTAL)

    load=Image.open('resources/Block.png')
    load=load.resize((160, 160), Image.ANTIALIAS)
    render=ImageTk.PhotoImage(load)
    table1=Label(mid,image=render)
    table1.image=render
    table1.place(x=30,y=180)
    table2=Label(mid,image=render)
    table2.image=render
    table2.place(x=265,y=180)

    Label(mid,text="Table of cases and deaths",font=('bold',10),justify="left",bg="white").place(x=34,y=345)
    Label(mid,text="Table of equations",font=('bold',10),justify="left",bg="white").place(x=292,y=345)

    #Helps the program to close
    root.protocol("WM_DELETE_WINDOW",root.destroy)

    #Ventanas modales
    #https://ic1800a2011.wordpress.com/2013/06/21/027-ejemplo-de-una-ventana-modal-en-tkinter-python-3-x/
    #Manejar excepciones con try
    #https://entrenamiento-python-basico.readthedocs.io/es/latest/leccion9/errores.html

    #Keeps the visual aspect open   
    root.mainloop()

#DOCUMENTACION PYDOC [https://github.com/JoshuaMeza/CodePain_PE/blob/master/Recursos/Documentaci%C3%B3nHTML.zip?raw=true]