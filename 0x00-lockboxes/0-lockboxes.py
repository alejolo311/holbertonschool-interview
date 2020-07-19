#!/usr/bin/python3


def canUnlockAll(boxes):
    """algorithm to solve the problem of
    loockboxes"""
    past = [False for i in range(len(boxes))]
    past[0] = True
    st = [0]
    while len(st):
        box = st.pop(0)
        for nBox in boxes[box]:
            if isinstance(nBox, int):
                if nBox >= 0 and nBox < len(boxes):
                    if not past[nBox]:
                        past[nBox] = True
                        st.append(nBox)
    return all(past)
