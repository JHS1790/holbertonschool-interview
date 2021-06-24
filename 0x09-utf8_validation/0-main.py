#!/usr/bin/python3
"""
Main file for testing
"""

validUTF8 = __import__('0-validate_utf8').validUTF8


data = [467, 133, 108]
print("Should be True:")
print(validUTF8(data))
print("------------------")

data = [240, 188, 128, 167]
print("Should be True:")
print(validUTF8(data))
print("------------------")

data = [235, 140]
print("Should be False:")
print(validUTF8(data))
print("------------------")

data = [345, 467]
print("Should be False:")
print(validUTF8(data))
print("------------------")

data = [250, 145, 145, 145, 145]
print("Should be False:")
print(validUTF8(data))
print("------------------")

data = [0, 0, 0, 0, 0, 0]
print("Should be True:")
print(validUTF8(data))
print("------------------")

data = []
print("Should be True:")
print(validUTF8(data))
print("------------------")
