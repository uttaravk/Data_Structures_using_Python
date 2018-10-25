"""
We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
Example:

Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14
Note: The input number n will not exceed 100,000,000. (1e8)
"""

# Method 1


# This method will not work for large numbers
def checkPerfectNumberMethod1(num):
    i = 1
    mysum = 0
    while i < num:
        if (num % i == 0):
            mysum += i
        i = i + 1
    if mysum == num:
        return True
    return False


# Method 2


# This method will work for large numbers as well
def checkPerfectNumberMethod2(num):
    if num <= 0:
        return False
    i = 1
    mysum = 0
    while i * i <= num:
        if (num % i == 0):
            mysum += i
            if i * i != num:
                mysum += num / i
        i = i + 1
    if mysum - num == num:
        return True
    return False


# Function Call
print(checkPerfectNumberMethod1(28))
print(checkPerfectNumberMethod2(28))
