import math

def gen(args):

    x = float(args["n"])
    k = 1
    i = 1
    while k <= 4:
        i = 1
        while i <= args["i1"]:
            while i < args["i0"]:
                x = k * x * ((1000 - x) / 1000)
                i += 1
            x = k * x * ((1000 - x) / 1000)
            print("{:.2f} {:.2f}".format(k, x))
            i += 1
        k += 0.01