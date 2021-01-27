#!/usr/bin/python3
"""
rotates 2D matrix using python
"""


def rotate_2d_matrix(matrix):
    """
    How to rotate a matrix 90 degrees
    """
    cpy = list(zip(*matrix[::-1]))
    i = len(matrix)
    j = len(matrix[0])
    for v in range(i):
        for e in range(j):
            matrix[v][e] = cpy[v][e]
