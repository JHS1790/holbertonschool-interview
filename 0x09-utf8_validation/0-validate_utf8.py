#!/usr/bin/python3
"""
Main file for testing
"""


def validUTF8(data):
    """ bitwise opperators are simpler than I anticipated """
    count = 0
    for i in range(len(data)):
        if data[i] > 255:
            data[i] >>= data[i].bit_length() - 8
    for byte in data:
        if count == 0:
            if (byte >> 6) == 0b00:
                count = 0
            elif (byte >> 6) == 0b10:
                return False
            elif (byte >> 5) == 0b110:
                count = 1
            elif (byte >> 4) == 0b1110:
                count = 2
            elif (byte >> 3) == 0b11110:
                count = 3
        else:
            if (byte >> 6) != 0b10:
                return False
            count -= 1
    return count == 0
