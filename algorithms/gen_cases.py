#!/usr/bin/python3

test_cases = 5
i = 1
print(test_cases)
while i < 21:
    j = 0
    print(10*i)
    while j < i * 10:
        from random import randint
        print(randint(0, 100))
        j += 1
    i += 1

