#!/usr/bin/python3
'''Damocles had the right idea'''


def canUnlockAll(boxes):
    if len(boxes) == 0:
        return False
    keys = [0]
    iteration = 0
    while len(keys) != len(boxes):
        working_keys = keys.copy()
        for i in keys:
            working_keys.extend(boxes[i])
            working_keys = list(set(working_keys))
            working_keys.sort()
        keys = working_keys.copy()
        for i in keys:
            if i >= len(boxes):
                working_keys.remove(i)
        keys = working_keys.copy()
        if iteration == len(boxes):
            return False
        iteration += 1
    return True
