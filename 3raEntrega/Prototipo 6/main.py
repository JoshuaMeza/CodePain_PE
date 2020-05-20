"""
Instruction to inicialize the program
Args:
    casesAmount (int): Total amount of confirmed cases
    deathsAmount (int): Total amount of deaths
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
from tkinter import *
from PutValues import *
from GenGraphic1 import *
from GenGraphic2 import *

def placeBoxes():
    casesAmount.clear()
    deathsAmount.clear()
    A.clear()
    B.clear()
    C.clear()
    D.clear()
    codeL=listCountries.get(listCountries.curselection())
    values(casesBox,eqCasBox,deathBox,eqDetBox,codeL,casesAmount,deathsAmount,A,B,C,D)

def genGraphCases():
    genGraphic1(casesAmount,deathsAmount)

def genGraphDeaths():
    genGraphic2(A,B,C,D)

#Memory for graphics
casesAmount=[0]
deathsAmount=[0]
A=[0]
B=[0]
C=[0]
D=[0]

#Visual Aspect
root=Tk()
codeL=StringVar()

root.title("Coronavirus Graphics")
root.geometry("465x390")

imgIcon = PhotoImage(file='resources/Icon.gif')
root.tk.call('wm','iconphoto', root._w, imgIcon)
root.resizable(0, 0)

top=Frame(root,width=465,height=50)
top.pack(anchor="n")
top.config(bg="#AEE8D7")

mid=Frame(root,width=465,height=310)
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

Button(mid,text="Submit",justify="center",activebackground="blue",command=placeBoxes).place(x=300,y=40)

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

Label(mid,text="Generate table of confirmed cases and deaths",font=('bold',10),justify="left",bg="white").place(x=92,y=180)
Button(mid,text="Generate",justify="center",activebackground="blue",command=genGraphCases).place(x=200,y=205)

Label(mid,text="Generate table of equations",font=('bold',10),justify="left",bg="white").place(x=148,y=240)
Button(mid,text="Generate",justify="center",activebackground="blue",command=genGraphDeaths).place(x=200,y=265)

#Helps the program to close
root.protocol("WM_DELETE_WINDOW",root.destroy)

#Keeps the visual aspect open   
root.mainloop()