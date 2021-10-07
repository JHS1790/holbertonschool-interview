#!/usr/bin/python3
"""
a program that solves the N queens problem.
"""
import sys


def main(N):
    solution = []
    solve_queens(0, N, solution)


def solve_queens(row, N, solution):
    if (row == N):
        print(solution)
    else:
        for column in range(N):
            position = [row, column]
            if valid_position(solution, position):
                solution.append(position)
                solve_queens(row + 1, N, solution)
                solution.remove(position)


def valid_position(solution, position):
    for queen in solution:
        if queen[1] == position[1]:
            return False
        if (queen[0] + queen[1]) == (position[0] + position[1]):
            return False
        if (queen[0] - queen[1]) == (position[0] - position[1]):
            return False
    return True


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        sys.exit(1)
    try:
        N = int(sys.argv[1])
    except BaseException:
        print('N must be a number')
        sys.exit(1)
    if N < 4:
        print('N must be at least 4')
        sys.exit(1)
    main(N)
