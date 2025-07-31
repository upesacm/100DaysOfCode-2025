from collections import deque

def max_in_queue(q):
    # Assuming the queue has at least one element
    maximum = q[0]
    for elem in q:
        if elem > maximum:
            maximum = elem
    return maximum

# Example 1:
queue1 = deque([3, 5, 1, 2])
print(max_in_queue(queue1))  # Output: 5

# Example 2:
queue2 = deque([10, 7, 4])
print(max_in_queue(queue2))  # Output: 10
