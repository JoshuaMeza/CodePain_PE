"""
Author Joshua Meza, Jonathan Gómez, and Irving Poot
Version 2.0.0
Program who ask to the user a Country and returns the graphics of total cases and total deaths, the
total numbers and the logarithmic ecuations that represents the increase of cases and deaths.
"""
import http.client 
import json
import math

#Functions
def askCountry():
    """
    Ask the country to the user
    Args:
        code (string): Code for the api
        selection (int): Read the selection of the user
    Returns:
        The code of the country
    """
    selection=0
    print("¿Qué país desea consultar?")
    print("(1) México")
    print("(2) Estados Unidos de América")
    print("(3) Canadá")

    while selection<1 or selection>3:
        selection=int(input("Ingrese el número del paréntesis: " ))

    if selection==1:
        code="mexico"
    else:
        if selection==2:
            code="usa"
        else:
            code="canada"

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
def main():
    #Input
    """
    Get the data from the API
    Args:
        totalCases (list): Saves the history of cases in integers
        totalDeaths (list): Saves the history of deaths in integers
        code (string): Code of the country for the api
    """
    totalCases=[]
    totalDeaths=[]
    
    code=askCountry()
    totalCases.extend(getCases(code))
    totalDeaths.extend(getDeaths(code))

    #Process
    """
    Obtains the values of the variables of the exponential equations
    ...
    Args:
        A (float): A value of the y=A*e^(Bx) equation
        B (float): B value of the y=A*e^(Bx) equation
        C (float): C value of the y=C*e^(Dx) equation
        D (float): D value of the y=C*e^(Dx) equation
    """
    A=getAvalue(totalCases)
    B=getBvalue(totalCases)
    C=getCvalue(totalDeaths)
    D=getDvalue(totalDeaths)
    #Output
    """
    Return the list and equations
    Args:
        totalCases (list): Saves the history of cases in integers
        totalDeaths (list): Saves the history of deaths in integers
        A (float): A value of the y=A*e^(Bx) equation
        B (float): B value of the y=A*e^(Bx) equation
        C (float): C value of the y=C*e^(Dx) equation
        D (float): D value of the y=C*e^(Dx) equation
    """
    print("Casos confirmados actuales: ", totalCases[0])
    print("Defunciones totales hasta hoy: ", totalDeaths[0])
    print("La ecuación que muestra el comportamiento de casos totales es y= ",A,"*e^(",B,"*x)")
    print("La ecuación que muestra el comportamiento de muertes es y= ",C,"*e^(",D,"*x)")

    return 0

if __name__=='__main__':
    main()
