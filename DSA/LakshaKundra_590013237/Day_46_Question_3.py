from collections import deque

def merge_queues(q1, q2):
    size = len(q2)
    for _ in range(size):
        q1.append(q2.popleft())
    return list(q1)

q1 = deque([1, 2])
q2 = deque([3, 4])
print(merge_queues(q1, q2))

q3 = deque([5])
q4 = deque([6, 7])
print(merge_queues(q3, q4))
