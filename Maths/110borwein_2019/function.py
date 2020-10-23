from math import *

def function(x, fun):
    if x == 0:
        return 1
    p = 1
    for i in range(fun + 1):
        p = p * (sin(x / (2 * i + 1)) / (x / (2 * i + 1)))
    return (p)