"""
Given an array consisting of n integers, find the contiguous subarray of
given length k that has the maximum average value. And you need to output
the maximum average value.

Example 1:

Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:

1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].

"""
nums = [1, 12, -5, -6, 50, 3]
k = 4


def initial_sum():
    init_sum = 0.0
    for j in range(0, k):
        init_sum += nums[j]
    return init_sum


def find_max_average(nums, k):
    max_avg = 0.0
    curr_avg = 0.0
    if len(nums) == 1:
        return float(nums[0])

    # Method 1
    curr_sum = float(sum(nums[:k]))

    # Method 2
    # curr_sum = initial_sum()

    max_avg = curr_sum / k
    for i in range(k, len(nums)):
        curr_sum = curr_sum + nums[i] - nums[i - k]
        curr_avg = curr_sum / k
        if curr_avg > max_avg:
            max_avg = curr_avg
    return max_avg


print(find_max_average(nums, k))
