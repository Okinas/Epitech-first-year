import math

def cylinder(args):
    if args['p'] < 0:
        exit (84)
    print("Cylinder of radius {}".format(args['p']))
    a = math.pow(args['xv'], 2) + math.pow(args['yv'], 2)
    b = 2 * args['xp'] * args['xv'] + 2 * args['yp'] * args['yv']
    c = math.pow(args['xp'], 2) + math.pow(args['yp'], 2) - math.pow(args['p'], 2)
    print("Line passing through the point ({}, {}, {}) and parallel to the vector ({}, {}, {})".format(args['xp'], args['yp'], args['zp'], args['xv'], args['yv'], args['zv']))
    if a == 0:
        print("There is an infinite number of intersection points.")
        exit()
    return (a, b, c)