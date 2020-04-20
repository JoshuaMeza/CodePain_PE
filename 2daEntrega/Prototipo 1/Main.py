"""
Author Joshua Meza, Jonathan Gómez, and Irving Poot
Version 1.0.0
Program who ask to the user a Country and returns the graphics of total cases and total deaths, the
total numbers and the logarithmic ecuations that represents the increase of cases and deaths.
"""
import http.client 
import json

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
    ...
    Args:
        ... (...): ...
    """


    #Output
    """
    Return the list
    Args:
        totalCases (list): Saves the history of cases in integers
        totalDeaths (list): Saves the history of deaths in integers
    """
    print("Casos confirmados actuales: ", totalCases[0])
    print("Defunciones totales hasta hoy: ", totalDeaths[0])

    return 0

if __name__=='__main__':
    main()
