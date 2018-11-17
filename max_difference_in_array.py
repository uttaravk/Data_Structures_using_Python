"""
Given an array,
find the maximum difference between an odd and an even number.

Condition:

All even numbers must not be to the right of an odd number;
if this is the case, then return -1
Otherwise, return the maximum difference


"""

import sys


def maxDifference(arr):
    min_odd = sys.maxsize
    max_diff = 0
    for i in arr:
        if i % 2 != 0:
            if i < min_odd:
                min_odd = i
            continue
        if (i - min_odd) > max_diff and min_odd != sys.maxsize:
            max_diff = i - min_odd
    if max_diff != 0:
        return max_diff
    else:
        return -1


arr = [2, 7, 2, 3, 5, 8]
print(maxDifference(arr))
