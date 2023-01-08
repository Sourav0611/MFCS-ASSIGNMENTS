#!/bin/env python3

'''
   QUESTION 1 )  Program to generate all possible truth values for n variables.
'''

def generateValues(val, n):
    if n == 0:
        print(val)
    else:
        for x in range(2):
            if x == 0:
                generateValues(val + 'T', n - 1)
            else:
                generateValues(val + 'F', n - 1)

print("Enter no. of variables: ", end="")
n = int(input())
print("")
generateValues("", n)
print("\nTotal generated possibilities: {}".format(2**n))
