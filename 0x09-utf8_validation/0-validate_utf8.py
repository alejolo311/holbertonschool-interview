#!/usr/bin/python3
"""validate UTF8"""


def validUTF8(data):
    """Validates UTF 8"""
    _byte = 0
    for index, value in enumerate(data):
        byte = value & 255
        if _byte:
            if byte >> 6 != 2:
                return False
            _byte -= 1
            continue
        while (1 << abs(7 - _byte)) & byte:
            _byte += 1
        if _byte == 1 or _byte > 4:
            return False
        _byte = max(_byte - 1, 0)
    return _byte == 0
