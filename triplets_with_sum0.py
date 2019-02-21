'''
Find all triplets with zero sum

Given an array of distinct elements.
The task is to find triplets in array whose sum is zero.
Examples :

Input : arr[] = {0, -1, 2, -3, 1}
Output : 0 -1 1
         2 -3 1

Input : arr[] = {1, -2, 1, 0, 5}
Output : 1 -2  1
'''


def triplets(arr):
    temp_sum = 0
    cnt = 0
    triplet = []
    res = []
    for i in arr:
        temp_sum += i
        cnt += 1
        triplet.append(i)
        if temp_sum != 0 and (-1 * temp_sum) in arr and cnt == 2 and triplet not in res:
            triplet.append(-1 * temp_sum)
            res.append(triplet)
            triplet = []
            cnt = 0
            temp_sum = 0
    return res


arr = [0, -1, 2, -3, 1]
print(triplets(arr))

arr = [1, -2, 1, 0, 5]
print(triplets(arr))
