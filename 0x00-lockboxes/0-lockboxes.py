#!/usr/bin/python3
'''Damocles had the right idea'''


def canUnlockAll(boxes):
    if len(boxes) == 0:
        return False
    keys = [0]
    iteration = 0
    while len(keys) != len(boxes):
        for i in keys:
            if i < len(boxes):
                keys.extend(boxes[i])
            keys = list(set(keys))
            keys.sort()
        if iteration == len(boxes) * 2:
            return False
        iteration += 1
    return True
