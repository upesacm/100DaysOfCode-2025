from collections import deque

queue = deque(map(int, input("Enter the Queue").split()))
print(len(queue))
# for example:
# Input: 1 2 3 4 5
# Output: 5