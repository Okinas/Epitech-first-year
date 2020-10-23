from math import *
from function import function

a = 0
b = 5000
n = 10000
h = (b - a) / n
pi_2 = pi / 2

def my_midpoint(fun):
    res = 0
    for i in range(n):
        res = res + function(a + i * h, fun)
    res = res * h
    print("I%d = %.10f" %(fun, res))
    if (res - pi_2 > -0.0000000001 and res - pi_2 < 0):
        print("diff = 0.0000000000\n")
    else:
        print("diff = %.10f\n" %(res - pi_2))