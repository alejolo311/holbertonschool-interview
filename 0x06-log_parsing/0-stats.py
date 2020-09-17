#!/usr/bin/python3
"""
log parsing
"""

import sys


def log_parser(log, counter, file_size, status):
    try:
        if log[-1].isdigit():
            file_size[0] += int(log[-1])
        if log[-2].isdigit():
            status[int(log[-2])] += 1
        if counter[0] == 9:
            printer(file_size, status)
            counter[0] = 0
        else:
            counter[0] += 1
    except Exception:
        pass


def printer(file_size, status):
    print("File size: {}".format(file_size[0]))
    for key in sorted(status.keys()):
        if status[key] != 0:
            print("{}: {}".format(key, status[key]))


if __name__ == "__main__":
    counter = [0]
    file_size = [0]
    status = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

    while True:
        try:
            log = input().split()
            log_parser(log, counter, file_size, status)
        except (KeyboardInterrupt, EOFError):
            printer(file_size, status)
            exit()
