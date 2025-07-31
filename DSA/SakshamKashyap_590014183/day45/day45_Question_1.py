from collections import deque

def sum_queue(q):
    total = 0
    for elem in q:
        total += elem
    return total

# Example usage:
queue = deque([1, 2, 3])
print(sum_queue(queue))  # Output: 6
