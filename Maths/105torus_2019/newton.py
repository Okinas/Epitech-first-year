import math
from function import function
from function import derivative

def newton(args, x0, n):
    if derivative(args, x0) == 0:
        exit(84)
    x = x0 - (function(args, x0) / derivative(args, x0))
    if x < 0 or x > 1:
        exit(84)
    if round(x, args['n']) != round(x0, args['n']):
        print("x = {:.{}f}".format(x, args['n']))
    if abs(function(args, x0)) > math.pow(10, -args['n']):
        newton(args, x, n + 1)
