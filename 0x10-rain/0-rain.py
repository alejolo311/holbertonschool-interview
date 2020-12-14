#!/usr/bin/python3
"""
Algorithm interview preparation
"""


def rain(walls):
    """
    calculate the Q of retained water
    """
    water = 0
    for i in range(1, len(walls) - 1):
        left = walls[i]
        for k in range(i):
            left = max(left, walls[k])
        right = walls[i]
        for k in range(i + 1, len(walls)):
            right = max(right, walls[k])
        water = water + (min(left, right) - walls[i])
    return water
