# Implement queue traversal with accumulative summation to calculate total values while maintaining queue integrity and structure.
from collections import deque

input_str = input("Enter the elements of the queue separated by spaces: ")

queue = deque(map(int, input_str.strip().split()))

total = 0
temp_queue = deque()

while queue:
    val = queue.popleft()
    total += val
    temp_queue.append(val)

queue = temp_queue

print("Output:")
print(total)
