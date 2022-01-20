#!/usr/bin/python3


def isWinner(x, nums):
    "Playing this game instead of working on my project"
    ben = 0
    maria = 0

    """print("There are {} rounds".format(x))"""
    for round in range(x):
        """print("  Round {}: Range {}".format(
            round + 1, list(range(1, nums[round] + 1))))"""
        failTurn = roundTurns(nums[round], list(range(1, nums[round] + 1)))
        """print("  The round failed on turn {}".format(failTurn))"""
        if failTurn % 2 == 0:
            """print("   Maria won")"""
            maria += 1
        else:
            """print("   Ben won")"""
            ben += 1

    if ben > maria:
        return "Ben"
    elif ben < maria:
        return "Maria"
    else:
        return "None"


def roundTurns(x, roundRange):
    turns = 1

    while(True):
        """print("    Turn {}:".format(turns))"""
        breakFlag = False
        for x in roundRange:
            primeProducts = []
            if checkPrime(x):
                primeProducts += [x]
                for y in roundRange:
                    if y % x == 0:
                        primeProducts += [y]
                breakFlag = True
                break
        if breakFlag:
            """print("      Removing {}".format(primeProducts))"""
            roundRange = [x for x in roundRange if x not in primeProducts]
            turns += 1
        else:
            """print("      Nothing to remove, turn failure")"""
            break

    return turns


def checkPrime(num):
    flag = False

    if num > 1:
        for i in range(2, int(num / 2) + 1):
            if (num % i) == 0:
                flag = False
                break
        else:
            flag = True

    return flag
