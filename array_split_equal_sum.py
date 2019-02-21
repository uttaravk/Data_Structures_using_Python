'''
Split an array into two equal Sum subarrays
Given an array of integers greater than zero,
find if it is possible to split it in two subarrays
(without reordering the elements), such that the sum of the two subarrays
is the same. Print the two subarrays.
'''


def split_array(arr):
    total_sum = 0
    for i in arr:
        total_sum += i

    half_sum = total_sum / 2
    sum = 0
    for i in range(len(arr)):
        sum += i
        if sum == half_sum:
            return i - 1
        elif sum > half_sum:
            return -1


arr = [1, 2, 3, 4, 5, 5]
print(split_array(arr))
