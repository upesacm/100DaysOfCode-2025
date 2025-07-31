from collections import deque

def compare_queues(q1, q2):
    if len(q1) != len(q2):
        return "No"
    for elem1, elem2 in zip(q1, q2):
        if elem1 != elem2:
            return "No"
    return "Yes"

# Examples:
Q1 = deque([1, 2, 3])
Q2 = deque([1, 2, 3])
print(compare_queues(Q1, Q2))  # Output: Yes

Q1 = deque([1, 2])
Q2 = deque([2, 1])
print(compare_queues(Q1, Q2))  # Output: No
