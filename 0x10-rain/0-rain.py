#!/usr/bin/python3
"""
0-rain
"""


def rain(walls):
    westWall = 0
    eastWall = 0
    resevoirVolume = 0
    while True:
        if eastWall >= len(walls):
            break
        if westWall == eastWall:
            eastWall += 1
            continue
        if walls[eastWall] == 0:
            eastWall += 1
            continue
        if walls[westWall] == 0:
            westWall += 1
            continue
        resevoirHeight = min(walls[westWall], walls[eastWall])
        resevoirWidth = eastWall - westWall - 1
        resevoirVolume += (resevoirHeight * resevoirWidth)
        westWall = eastWall
        eastWall += 1
    return resevoirVolume
