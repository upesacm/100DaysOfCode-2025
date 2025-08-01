#: Implement queue traversal with minimum tracking to identify the smallest element while preserving queue state and maintaining computational efficiency.
from collections import deque

elements = input("Enter the elements of the queue separated by spaces: ")
elements_list = list(map(int, elements.strip().split()))

queue = deque(elements_list)

min_value = float('inf')
for item in queue:
    if item < min_value:
        min_value = item

print("Minimum element in the queue:", min_value)
