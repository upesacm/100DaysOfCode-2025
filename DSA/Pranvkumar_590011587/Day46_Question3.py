from collections import deque

def merge_queues(q1, q2):
    merged = deque(q1)
    merged.extend(q2)
    return merged

# Example usage:
Q1 = deque([1, 2])
Q2 = deque([3, 4])
result = merge_queues(Q1, Q2)  
print(result)