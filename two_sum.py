"""
Given an array of integers, return indices of the two numbers such that they
add up to a specific target.

You may assume that each input would have exactly one solution, and you may
not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

"""


def two_sum(nums, target):
    curr_diff = target - nums[0]
    pairs = {curr_diff: 0}
    num1 = 0
    num2 = 0
    for i in range(1, len(nums)):
        curr_diff = target - nums[i]
        if nums[i] in pairs.keys():
            num1 = i
            num2 = pairs[nums[i]]
            break
        else:
            pairs.update({curr_diff: i})
    pairs_list = [num2, num1]
    return pairs_list


nums = [2, 7, 11, 15]
target = 9
print (two_sum(nums, target))
