"""
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
"""

# Implementing Stack functionality


class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[len(self.items) - 1]

    def size(self):
        return len(self.items)


# Solution using Stack and Dictionary
def isValid(s):
    stk = Stack()
    if len(s) == 0:
        return True
    mydict = {'{': '}', '[': ']', '(': ')'}
    for i in s:
        if i in mydict:
            stk.push(i)
        else:
            if stk.is_empty():
                return False
            if mydict[stk.pop()] != i:
                return False
    if not stk.is_empty():
        return False
    return True


# Function Call
print(isValid("([)]"))
