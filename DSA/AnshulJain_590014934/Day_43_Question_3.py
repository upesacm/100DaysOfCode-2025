from collections import deque
queue = deque(input("Enter characters without spaces: "))#Taing input from the user
stack = []
for ch in queue:
    stack.append(ch)
is_palindrome = True
for ch in queue:
    if ch != stack.pop():
        is_palindrome = False
        break
print("Yes" if is_palindrome else "No")
