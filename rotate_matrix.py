"""
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees(clockwise).
Note:
You have to rotate the image in-place, which means you have to modify the input
2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:
Given input matrix =
[
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
],

rotate the input matrix in-place such that it becomes:
[
    [7, 4, 1],
    [8, 5, 2],
    [9, 6, 3]
]
Example 2:

Given input matrix =
[
    [5, 1, 9, 11],
    [2, 4, 8, 10],
    [13, 3, 6, 7],
    [15, 14, 12, 16]
],

rotate the input matrix in-place such that it becomes:
[
    [15, 13, 2, 5],
    [14, 3, 4, 1],
    [12, 6, 8, 9],
    [16, 7, 10, 11]
]

"""
"""
Method 1:
This command calculate the transpose of a matrix and reverses it in place
As a result, we get 90 degree rotated matrix
"""
def rotateMethod1(matrix):
    matrix[:] = zip(*matrix[::-1])



# Method 2
def rotateMethod2(matrix):
    # Calculating the transpose of a matrix
    for i in range(0, len(matrix[0])):
        for j in range(0, len(matrix[0])):
            if j >= i:
                temp = matrix[j][i]
                matrix[j][i] = matrix[i][j]
                matrix[i][j] = temp
    # Flipping the matrix by interchanging the columns
    for j in range(0, len(matrix[0]) / 2):
        for i in range(0, len(matrix[0])):
            temp = matrix[i][len(matrix[0]) - 1 - j]
            matrix[i][len(matrix[0]) - 1 - j] = matrix[i][j]
            matrix[i][j] = temp


# Function Calls
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
rotateMethod1(matrix)
print(matrix)
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
rotateMethod2(matrix)
print(matrix)
