from collections import deque

def merge_queues(q1, q2):
    while q2:
        q1.append(q2.popleft())
    return q1

#example
q1 = deque([44, 56])
q2 = deque([78, 92])
result = merge_queues(q1, q2)
print(list(result))