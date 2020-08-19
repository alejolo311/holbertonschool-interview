#!/usr/bin/python3
"""minimun"""

from math import sqrt


def minOperations(n):
    """obtain the minimun"""
    ope = 0
    if n <= 1:
        return 0
    for i in range(2, int(sqrt(n) + 1)):
        while n % i == 0:
            ope = ope + i
            n = n / i
            if n <= 1:
                break
    if n > 1:
        ope = ope + int(n)
    return ope
