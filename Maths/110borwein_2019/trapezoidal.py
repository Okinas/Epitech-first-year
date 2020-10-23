from math import *
from function import function

a = 0
b = 5000
n = 10000
h = (b - a) / n
pi_2 = pi / 2

def my_trapezoidal(fun):
    res = 0
    for i in range(1, n):
        res += function(a + i * h, fun)
    res = res * 2
    res = res + (function(a, fun) + function(b, fun))
    res = res * (h / 2)
    print("I%d = %.10f" %(fun, res))
    if (res - pi_2 > -0.0000000001 and res - pi_2 < 0):
        print("diff = 0.0000000000\n")
    else:
        print("diff = %.10f\n" %(abs(res - pi_2)))