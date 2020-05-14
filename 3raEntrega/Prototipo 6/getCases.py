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

import http.client 
import json 
import math
from matplotlib import pyplot
import numpy as np
from math import exp
import shutil
from tkinter import * #Ignore warnings
from PIL import Image,ImageTk


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