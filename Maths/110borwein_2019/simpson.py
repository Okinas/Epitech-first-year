from math import *
from function import function

a = 0
b = 5000
n = 10000
h = (b - a) / n
pi_2 = pi / 2

def my_simpson(fun):
    res1 = 0
    res2 = 0
    for i in range(0, n):
        res1 += function(a + i * h + h / 2, fun)
    res1 = res1 * 4
    for i in range(1, n):
        res2 += function(a + i * h, fun)
    res2 = res2 * 2
    res = res1 + res2
    res = res + (function(a, fun) + function(b, fun))
    res = res * (h / 6)
    print("I%d = %.10f" %(fun, res))
    if (res - pi_2 > -0.0000000001 and res - pi_2 < 0):
        print("diff = 0.0000000000")
    else:
        print("diff = %.10f" %(abs(res - pi_2)))