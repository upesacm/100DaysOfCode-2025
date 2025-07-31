from collections import deque

def find_min(queue):
    min_val = float('inf')
    size = len(queue)
    for _ in range(size):
        val = queue.popleft()
        if val < min_val:
            min_val = val
        queue.append(val)
    return min_val

q1 = deque([4, 2, 7, 1])
print(find_min(q1))

q2 = deque([9, 3])
print(find_min(q2))
