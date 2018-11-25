
"""
Design a stack that supports push, pop, top, and
retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

"""
import sys


class MinStack(object):
    def __init__(self):
        self.stack = []
        self.min_element = sys.maxint

    def push(self, x):
        if self.min_element > x:
            self.min_element = x
        self.stack.append(x)

    def pop(self):
        if len(self.stack):
            pos = len(self.stack) - 1
            element = self.stack[pos]
            del self.stack[pos]

    def top(self):
        if len(self.stack):
            pos = len(self.stack) - 1
            element = self.stack[pos]
            return element
        else:
            return 0

    def getMin(self):
        if self.min_element in self.stack:
            return self.min_element
        else:
            self.min_element = min(self.stack)
            return self.min_element


minStack = MinStack()
print(minStack.push(-2))
print(minStack.push(0))
print(minStack.push(-3))
print(minStack.getMin())
print(minStack.pop())
print(minStack.top())
print(minStack.getMin())
