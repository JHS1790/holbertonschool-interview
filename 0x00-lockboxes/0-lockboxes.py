#!/usr/bin/python3
'''Damocles had the right idea'''


def canUnlockAll(boxes):
    if len(boxes) == 0:
        return False
    keys = [0]
    iteration = 0
    while len(keys) != len(boxes):
        for i in keys:
            if i >= len(boxes):
                keys.remove(i)
        for i in keys:
            keys.extend(boxes[i])
            keys = list(set(keys))
            keys.sort()
        print(keys)
        if iteration == len(boxes):
            return False
        iteration += 1
    return True