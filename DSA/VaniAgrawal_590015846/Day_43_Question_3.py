# Use complementary queue and stack operations to systematically compare sequence elements for palindrome detection through structural symmetry analysis.
from collections import deque

s = input("Enter characters separated by space: ").split()

queue = deque()
stack = []

for char in s:
    queue.append(char)
    stack.append(char)

is_palindrome = True
while queue:
    if queue.popleft() != stack.pop():
        is_palindrome = False
        break

if is_palindrome:
    print("Yes")
else:
    print("No")
