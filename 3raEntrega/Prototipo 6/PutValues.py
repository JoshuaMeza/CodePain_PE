"""
Author Joshua Meza, Jonathan Gómez, and Irving Poot
Date 20/05/2020
Version 1.0.0
Program who recieve data form the api and place it on the box.
"""
import http.client 
import json 
import math

def askCountry(codeL):
    """
    Ask the country to the user
    Args:
        code (string): Code for the api
        selection (int): Read the selection of the user
    Returns:
        The code of the country
    """
    if codeL=="Mexico":
        code=codeL
    else:
        if codeL=="United States":
            code="USA"
        else:
            code="Canada"

    return code

def getCases(_code):
    """
    Function that gets in integers the list of confirmed cases
    Args:
        _totalCases (list): List with the history of confirmed cases in integers
        conn (http): Connection
        headers (http): Section of data
        res (http): Information response
        data (http):  Vector of bytes with the information
        dictionary (dict): Dictionary of the information
        case (int): Cases in the dictionary
        _code (string): Code of the country for the api
    Returns:
        The list of cases
    """
    _totalCases=[]
    conn = http.client.HTTPSConnection("covid-193.p.rapidapi.com")

    headers = {
        'x-rapidapi-host': "covid-193.p.rapidapi.com",
        'x-rapidapi-key': "8b5b3cbb4fmsh31f42c5c7a3c781p1f3d0djsnac417872395a"
    }
    
    conn.request("GET", "/history?country=" + _code, headers=headers)

    res = conn.getresponse()
    data = res.read()

    dictionary=json.loads(data)

    for case in dictionary['response']:
        _totalCases.append(int(case['cases']['total']))

    return _totalCases

def getDeaths(_code):
    """
    Function that gets in integers the history of deaths
    Args:
        _totalDeaths (list): List with the history of deaths in integers
        conn (http): Connection
        headers (http): Section of data
        res (http): Information response
        data (http):  Vector of bytes with the information
        dictionary (dict): Dictionary of the information
        deaths (int): Deaths in the dictionary
        _code (string): Code of the country for the api
    Returns:
        The list of amounts of deaths
    """
    _totalDeaths=[]
    conn = http.client.HTTPSConnection("covid-193.p.rapidapi.com")

    headers = {
        'x-rapidapi-host': "covid-193.p.rapidapi.com",
        'x-rapidapi-key': "8b5b3cbb4fmsh31f42c5c7a3c781p1f3d0djsnac417872395a"
    }

    conn.request("GET", "/history?country=" + _code, headers=headers)

    res = conn.getresponse()
    data = res.read()

    dictionary=json.loads(data)

    for deaths in dictionary['response']:
        _totalDeaths.append(int(deaths['deaths']['total']))
    
    return _totalDeaths

def getAvalue(totalCases):
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

def getBvalue(totalCases):
    """
    Function that gets the B value of the y=A*e^(Bx) equation
    Args:
        totalCases (list): List with the history of cases in integers
        count (int)= counts the number of values in totalCases
        x (int): summation of the x values (number of day)
        y (float): summation of the natural logarithm of the y values(number of cases)
        sum1 (float): summation of the natural logarithm of the y values multiplied with the x values
        x2 (int): summation of the quadratic values of x
        n (int): last x value
        i (int): counter variable
    Returns:
        The B value of the equation
    """
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
    return B

def getCvalue(totalDeaths):
    """
    Function that gets the C value of the y=C*e^(Dx) equation
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
        The C value of the equation
    """
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
        
    B=(n*(sum1)-x*y)/(n*x2-x**2)
    A=(y/n)-B*(x/n)
    C=2.7182818284590452**A
    return C

def getDvalue(totalDeaths):
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

def values(casesBox,eqCasBox,deathBox,eqDetBox,codeL,casesAmount,deathsAmount,A,B,C,D):
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
    code=askCountry(codeL)
    totalCases.extend(getCases(code))
    totalDeaths.extend(getDeaths(code))
    casesAmount.append(totalCases[0])
    deathsAmount.append(totalDeaths[0])

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
    A.append(getAvalue(totalCases))
    B.append(getBvalue(totalCases))
    C.append(getCvalue(totalDeaths))
    D.append(getDvalue(totalDeaths))

    #Output
    """
    Put the values on the boxes
    Args: 
        casesBox (tkinter): Box of confirmed cases
        deathBox (tkinter): Box of deaths
        eqCasBox (tkinter): Box of the cases equation
        eqDetBox (tkinter): Box of the deaths equation
        output (string): String of the equation
    """

    casesBox.delete(0)
    casesBox.insert(0,casesAmount[0])
    eqCasBox.delete(0)
    output=str("y={}*e^({}*x)".format(A[0],B[0]))
    eqCasBox.insert(0,output)
    deathBox.delete(0)
    deathBox.insert(0,deathsAmount[0])
    eqDetBox.delete(0)
    output=str("y={}*e^({}*x)".format(C[0],D[0]))
    eqDetBox.insert(0,output)

