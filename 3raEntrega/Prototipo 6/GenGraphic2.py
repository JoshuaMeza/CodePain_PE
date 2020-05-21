"""
Author Joshua Meza, Jonathan Gómez, and Irving Poot
Date 20/05/2020
Version 1.0.0
Program who generates the equations graphic.
"""
from matplotlib import pyplot
from math import exp
import numpy as np

def genGraphic2(A, B, C, D):
    """
    Function that generates the first graphic
    Args:
        A (float): A value of the y=A*e^(Bx) equation
        B (float): B value of the y=A*e^(Bx) equation
        C (float): C value of the y=C*e^(Dx) equation
        D (float): D value of the y=D*e^(Dx) equation
        e (int): Stores the euler value
        f (int): Stores the first ecuation
        g (int): Stores the second ecuation
        v (Lista): Stores the limits of the graphic
        x (int): Stores the cases to use
    Returns:
        Nothing
    """
    if A[0]!=0 and B[0]!=0 and C[0]!=0 and D[0]!=0: 
        e = exp(1)
        f = lambda x: A[0]*(e**(B[0]*x))

        g= lambda x: C[0]*(e**(D[0]*x))
        v = [-25, 25, 0, 25]
        x =np.linspace(-25,25,100)
        pyplot.ion()
        pyplot.rcParams['toolbar'] = 'None'
        pyplot.plot(x,f(x),'g',label='Confirmed Cases')
        pyplot.plot(x,g(x),'r', label='Deaths')
        pyplot.xlabel('Time')
        pyplot.ylabel('Amount')
        pyplot.title('Future forecast')
        pyplot.legend()
        pyplot.axis(v)
        pyplot.grid()
        pyplot.show()
