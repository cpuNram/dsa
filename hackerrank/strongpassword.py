#!/bin/python

import sys

def minimumNumber(n, password):
    TypesDict = {"digits": 0, "upper": 0, "lower": 0, "special": 0}
    specialchars = "!@#$%^&*()-+"
    for char in password:
        if char.isdigit():
            TypesDict["digits"]+=1
        if char.islower():
            TypesDict["lower"]+=1
        if char.isupper():
            TypesDict["upper"]+=1
        elif char in specialchars :
            TypesDict["special"]+=1
    cnt = 0
    for i in TypesDict.values():
        if i < 1:
            cnt+=1
    return max(6-n, cnt)

if __name__ == "__main__":
    n = int(raw_input().strip())
    password = raw_input().strip()
    answer = minimumNumber(n, password)
    print answer
