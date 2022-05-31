#!/usr/bin/python3

def print_last_digit(n):
    tmp = n
    if tmp < 0:
        tmp = (-1) * n
    last_digit = tmp % 10
    print("{}".format(last_digit), end="")
    return last_digit
