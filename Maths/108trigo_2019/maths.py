from math import *

def pow_mat(mat1, n):
    tab = mat1
    for a in range(n - 1):
        tab = mat_mult(tab, mat1)
    return (tab)

def div_mat(mat1, k):
    for a in range(len(mat1)):
        for b in range(len(mat1[0])):
            mat1[a][b] = mat1[a][b] / k
    return (mat1)

def add_mat(mat1, mat2):
    tab = []
    for a in range(len(mat1)):
        tab2 = []
        for b in range(len(mat1[0])):
            tab2.append(mat1[a][b] + mat2[a][b])
        tab.append(tab2)
    return (tab)

def sub_mat(mat1, mat2):
    tab = []
    for a in range(len(mat1)):
        tab2 = []
        for b in range(len(mat1[0])):
            tab2.append(mat1[a][b] - mat2[a][b])
        tab.append(tab2)
    return (tab)

def mat_mult(mat1, mat2):
    tab = []
    for a in range(len(mat1)):
        tab2 = []
        for b in range(len(mat2[0])):
            d = 0
            for c in range(len(mat1[0])):
                d = d + mat1[a][c] * mat2[c][b]
            tab2.append(d)
        tab.append(tab2)
    return (tab)

def mat_identity(n):
    tab = []
    for a in range(n):
        tab2 = []
        for b in range(n):
            tab2.append(1 if b == a else 0)
        tab.append(tab2)
    return (tab)