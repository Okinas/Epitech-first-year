from maths import *

def sinh_calc(tab):
    tmp = tab
    for a in range(1, 17):
        tmp = add_mat(tmp, div_mat(pow_mat(tab, 2 * a + 1), factorial(2 * a + 1)))
    return (tmp)

def sin_calc(tab):
    tmp = tab
    for a in range(1, 17):
        if a % 2 == 0:
            tmp = add_mat(tmp, div_mat(pow_mat(tab, 2 * a + 1), factorial(2 * a + 1)))
        else:
            tmp = sub_mat(tmp, div_mat(pow_mat(tab, 2 * a + 1), factorial(2 * a + 1)))
    return (tmp)

def cos_calc(tab):
    tmp = mat_identity(len(tab))
    for a in range(1, 17):
        if a % 2 == 0:
            tmp = add_mat(tmp, div_mat(pow_mat(tab, 2 * a), factorial(2 * a)))
        else:
            tmp = sub_mat(tmp, div_mat(pow_mat(tab, 2 * a), factorial(2 * a)))
    return (tmp)

def cosh_calc(tab):
    tmp = mat_identity(len(tab))
    for a in range(1, 17):
        tmp = add_mat(tmp, div_mat(pow_mat(tab, 2 * a), factorial(2 * a)))
    return (tmp)

def exp_calc(tab):
    tmp = mat_identity(len(tab))
    for a in range(1, 18):
        tmp = add_mat(tmp, div_mat(pow_mat(tab, a), factorial(a)))
    return (tmp)