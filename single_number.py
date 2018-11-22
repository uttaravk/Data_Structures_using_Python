"""
Given a non-empty array of integers, every element appears twice except for one.
Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement
it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
"""

# Method 1 using Counter collection
import collections


def single_number_method_1(nums):
    num_count = collections.Counter(nums)
    for num, cnt in num_count.items():
        if cnt == 1:
            return num


# Method 2 using XOR principle


def single_number_method_2(nums):
    x = 0
    for num in nums:
        x ^= num
    return x


# Function Calls
nums = [4, 1, 2, 6, 5, 1, 2, 4, 6]
print(single_number_method_1(nums))
print(single_number_method_2(nums))
