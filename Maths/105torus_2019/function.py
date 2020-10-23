import math

def function(args, x):
    result = math.pow(x, 4) * args['a4'] + math.pow(x, 3) * args['a3'] + math.pow(x, 2) * args['a2'] + x * args['a1'] + args['a0']
    return (result)

def derivative(args, x):
    result = 4 * math.pow(x, 3) * args['a4'] + 3 * math.pow(x, 2) * args['a3'] + 2 * x * args['a2'] + args['a1']
    return (result)