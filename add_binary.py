"""
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
"""
a = "1010"
b = "1011"


def add_binary_method1(a, b):
    max_len = max(len(a), len(b))
    a = a.zfill(max_len)
    b = b.zfill(max_len)

    sum = 0
    result = ""
    carry = 0
    i = max_len - 1

    while(i >= 0):
        sum = int(a[i]) + int(b[i]) + carry
        if sum == 3:
            result = "1" + result
            carry = 1
        elif sum == 2:
            result = "0" + result
            carry = 1
        elif sum == 1:
            result = "1" + result
            carry = 0
        elif sum == 0:
            result = "0" + result
            carry = 0
        i -= 1
    if carry:
        result = "1" + result
    return result


def add_binary_method2(a, b):
    max_len = max(len(a), len(b))
    a = a.zfill(max_len)
    b = b.zfill(max_len)

    sum = 0
    result = ""
    carry = 0
    i = max_len - 1

    while(i >= 0):
        sum = int(a[i]) + int(b[i]) + carry
        result = str(sum % 2) + result
        carry = int(sum / 2)
        i -= 1
    if carry:
        result = "1" + result
    return result


def add_binary_method3(a, b):
    return str(bin((int(a, 2) + int(b, 2))))[2:]


print(add_binary_method1(a, b))
print(add_binary_method2(a, b))
print(add_binary_method3(a, b))
