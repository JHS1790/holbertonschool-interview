#!/usr/bin/python3
"""
0-rain
"""


def rain(walls):
    resevoirVolume = 0
    for i in range(1, len(walls) - 1):
        westWall = walls[i]
        for j in range(i):
            westWall = max(westWall, walls[j])
        eastWall = walls[i]
        for j in range(i + 1, len(walls)):
            eastWall = max(eastWall, walls[j])
        resevoirVolume += min(eastWall, westWall) - walls[i]
    return resevoirVolume
