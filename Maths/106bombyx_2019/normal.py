import math

def normal(args):
    x = args["n"]
    for i in range(1, 101):
        print("{} {:.2f}".format(i, x))
        x = args["k"] * x * ((1000 - x) / 1000)