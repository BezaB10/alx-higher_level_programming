#!/usr/bin/python3

def print_last_digit(number):
    tmp = number
    if tmp < 0:
        tmp = (-1) * number
    last_digit = tmp % 10
    print("{}".format(last_digit), end="")
    return last_digit
