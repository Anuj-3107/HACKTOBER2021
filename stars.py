#!/bin/python3

def input_value(bar):
    foo = input(bar)
    foo = check_num(foo, bar)
    return foo

def check_num(foo, bar):
    try:
        foo = int(foo)
        if int(foo) > 0:
            return foo
        else:
            error_msg(foo)
            foo = input(bar)
            return foo
    except:
        error_msg(foo)
        foo = input(bar)
        return foo

def error_msg(foo):
    print(f"{foo} is invalid. Please give me an positive number.")

def rows(bar, foo):
    for i in range(1, foo + 1):
        star = ""
        for x in range(1, bar + 1):
            star += "*"
        print(star)

def main():
    rows(input_value("How many colums of stars you want? "), input_value("How many rows of stars shoud i print? "))

main()