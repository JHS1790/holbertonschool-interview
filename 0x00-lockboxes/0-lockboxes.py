#!/usr/bin/python3
'''Damocles had the right idea'''


def canUnlockAll(boxes):
    keys = [0]
    iteration = 0
    while len(keys) != len(boxes):
        new_keys = keys
        for i in new_keys:
            new_keys.extend(boxes[i])
            new_keys = list(set(new_keys))
            new_keys.sort()
        if iteration == len(boxes):
            return False
        keys = new_keys
        iteration += 1
    return True
