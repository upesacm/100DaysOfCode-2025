from collections import deque

def is_palindrome(q):
    stack = []
    for ch in q:
        stack.append(ch)
    for ch in q:
        if ch != stack.pop():
            return "No"
    return "Yes"

# Example 1
q1 = deque(['r', 'a', 'c', 'e', 'c', 'a', 'r'])
print(is_palindrome(q1))

# Example 2
q2 = deque(['a', 'b', 'c'])
print(is_palindrome(q2))
