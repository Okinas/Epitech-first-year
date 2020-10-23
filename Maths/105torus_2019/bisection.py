import math
from function import function

def bisection(args):
    a = 0
    b = 1
    p = args['n']

    if function(args, a) * function(args, b) >= 0:
        exit(84)
    while (b - a) > math.pow(10, -p):
        m = (a + b) / 2
        if float(m) == m and len(str(m)) - 1 < p:
            print("x = {:.{}f}".format(m, p).rstrip("0"))
        else:
            print("x = {:.{}f}".format(m, p))
        if function(args, a) * function(args, m) < 0:
            b = m
        else:
            a = m