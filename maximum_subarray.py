"""
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
"""
import sys


# Brute Force
def max_sub_array_method1(nums):
    if not nums:
        return 0
    sum = min(nums)
    count = nums[0]
    for i in range(1, len(nums)):
        if nums[i] >= 0:
            if count < 0:
                count = nums[i]
            else:
                count = count + nums[i]
            if count > sum:
                sum = count
        elif nums[i] < 0:
            if nums[i] >= count:
                count = nums[i]
            else:
                if count > 0:
                    count = count + nums[i]
            if count > sum:
                sum = count
    if sum < max(nums):
        sum = max(nums)
    return sum


# Using system module
def max_sub_array_method2(nums):
    result = -sys.maxint
    sum = 0
    for i in range(len(nums)):
        sum = max(nums[i], sum + nums[i])
        result = max(result, sum)
    return result


nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
print(max_sub_array_method1(nums))
print(max_sub_array_method2(nums))
