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


def twoSum(nums, target):
    currDiff = target - nums[0]
    pairs = {currDiff: 0}
    num1 = 0
    num2 = 0
    for i in range(1, len(nums)):
        currDiff = target - nums[i]
        if nums[i] in pairs.keys():
            num1 = i
            num2 = pairs[nums[i]]
            break
        else:
            pairs.update({currDiff: i})
    pairsList = [num2, num1]
    return pairsList


nums = [2, 7, 11, 15]
target = 9
print (twoSum(nums, target))
