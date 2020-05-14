"""
Ask the country to the user
Args:
    code (string): Code for the api
    selection (int): Read the selection of the user
Returns:
    The code of the country
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


if codeL=="Mexico":
    code="mexico"
else:
    if codeL=="United States":
        code="usa"
    else:
        code="canada"

return code