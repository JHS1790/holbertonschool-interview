#!/usr/bin/python3
"""
boi howdy, it's me, spike
"""


def rotate_2d_matrix(matrix):
    N = len(matrix[0])
    for x in range(N // 2):
        for y in range(x, N-x-1):
            temp = matrix[x][y]
            matrix[x][y] = matrix[N-1-y][x]
            matrix[N-1-y][x] = matrix[N-1-x][N-1-y]
            matrix[N-1-x][N-1-y] = matrix[y][N-1-x]
            matrix[y][N-1-x] = temp
