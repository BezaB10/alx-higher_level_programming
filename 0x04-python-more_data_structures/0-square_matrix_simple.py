#!/usr/bin/python3
def square_matrix_simple(matrix=[]):
    sv = []
    for row in matrix:
        sv.append([i**2 for i in row])
    return sv
