# Implement queue traversal with maximum tracking to identify the largest element while preserving queue state and maintaining efficiency.
from collections import deque

input_str = input("Enter elements of the queue separated by spaces: ")

queue = deque(map(int, input_str.strip().split()))

max_val = float('-inf')
temp_queue = deque()

while queue:
    val = queue.popleft()
    if val > max_val:
        max_val = val
    temp_queue.append(val)

queue = temp_queue

print("Output:")
print(max_val)
