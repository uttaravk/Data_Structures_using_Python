
"""
Design a stack that supports push, pop, top, and
retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
get_min() -- Retrieve the minimum element in the stack.
Example:

min_stack min_stack = new min_stack();
min_stack.push(-2);
min_stack.push(0);
min_stack.push(-3);
min_stack.get_min();   --> Returns -3.
min_stack.pop();
min_stack.top();      --> Returns 0.
min_stack.get_min();   --> Returns -2.

"""
import sys


class min_stack(object):
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

    def get_min(self):
        if self.min_element in self.stack:
            return self.min_element
        else:
            self.min_element = min(self.stack)
            return self.min_element


min_stack = min_stack()
print(min_stack.push(-2))
print(min_stack.push(0))
print(min_stack.push(-3))
print(min_stack.get_min())
print(min_stack.pop())
print(min_stack.top())
print(min_stack.get_min())
