import math
from function import function

def secant(args, x0, x1):
    for loop in range(100):
        if function(args, x1) - function(args, x0) == 0:
            exit(84)
        x2 = x1 - ((x1 - x0) / (function(args, x1) - function(args, x0))) * function(args, x1)
        if x2 < 0 or x2 > 1:
            exit(84)
        if (abs((x2 - x1)) / abs((x2)) < 10**-args['n']):
            if ("{0:.{1}g}".format(x2, args['n']) == "{0:.{1}g}".format(x2, args['n'] + 15)):
                print("x = {0:.{1}g}".format(x2, args['n']))
            else:
                print("x = {0:.{1}f}".format(x2, args['n']))
            exit(0)
        else:
            if ("{0:.{1}g}".format(x2, args['n']) == "{0:.{1}g}".format(x2, args['n'] + 15)):
                print("x = {0:.{1}g}".format(x2, args['n']))
            else:
                print("x = {0:.{1}f}".format(x2, args['n']))
        x0 = x1
        x1 = x2
        