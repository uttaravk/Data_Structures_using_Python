
import sys
import string
from collections import Counter

# To apply Counter to words, convert string of words into list
#from collections import Counter
s = ["a", "abc", "a"]
s = "abbbaaa"
s_counter = Counter(s)
print(s_counter)

# Iterate through keys and values of the Counter or Normal dictionary
for key, val in s_counter.items():
    print("key:", key)
    print("val: ", val)

# Check if key 'a' is present
if 'a' in s_counter.keys():
    print("val associated with key 'a' is ", s_counter['a'])

# Convert string of words to list
words = "hello world"
mylist = words.split(' ')
print(mylist)

# Convert set to list
myset = (1, 2, 3)
mylist = list(myset)
print(mylist)

# Copy old list into new list
old_list = ['uk', 1, 3, 3]
new_list = list(old_list)
print(new_list)

# Remove punctuation and convert text into list
#import string
text = 'hello, world!'
words = (text.translate(None, string.punctuation)).split(" ")
print(words)

# convert the words into lower and find unique words
unique_words = set([word.lower() for word in words])
print(unique_words)


# Resizes string with specified width and appends 0 to the left
a = "Hello"
print(a.zfill(10))

print(pow(2, 2))  # Output: 4
print(pow(2, -2))  # Output: 0.25

# Sorting in reverse order
g = [2, 9, 8, 7]
g.sort(reverse=True)
print(g)

# Reverse a String or iterate in a reverse order
new_str = ""
for i in a[::-1]:
    new_str += i
print(new_str)

# 2d array
image = [[1, 1, 1], [1, 1, 0], [1, 0, 1]]
print(image[0][2])

# Accept input from user - (positive and negative)
user_input = raw_input()

# Get Max value of int
# import sys
max_pos_int = sys.maxsize
max_neg_int = -sys.maxsize
print(max_pos_int)
print(max_neg_int)

# get min and max values out of the list or by comparing variable values
print(min(g))
print(max(max_neg_int, max_pos_int))


# Create 0 filled 2d matrix
mat = [[0 for i in range(0, 12)]for j in range(0, 12)]

# Calculate the transpose of a matrix and reverses it in place,
# we get 90 degree rotated matrix
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
matrix[:] = zip(*matrix[::-1])
print(matrix)

# print a character or word several times
print('a' * 10)

# Check if the string contains only digit:
a = "1234"
print(a.isdigit())

# For 2d array you need to append an array to the outer array
inner_array = [1, 2, 3, 4]
outer = []
outer.append(inner_array)
print(outer)


'''
Given a array of integers, every element appears twice except for one.
Find that single one.
x = 0
for num in nums:
    x ^= num
return x
'''

'''
Roman Numbers
    first = ["\0", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
    ten = ["\0", "X", "XX", "XXX",
           "XL", "L", "LX", "LXX", "LXXX", "XC"]
    hundred = ["\0", "C", "CC", "CCC",
               "CD", "D", "DC", "DCC", "DCCC", "CM"]
    thousand = ["\0", "M", "MM", "MMM"]
    romanInt = {'M': 1000, 'D': 500, 'C': 100,
                'L': 50, 'X': 10, 'V': 5, 'I': 1}
'''
