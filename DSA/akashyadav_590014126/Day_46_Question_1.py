from collections import deque

def find_min(queue):
    temp_queue = deque()
    min_val = float('inf')

    while queue:
        curr = queue.popleft()
        min_val = min(min_val, curr)
        temp_queue.append(curr)

    while temp_queue:
        queue.append(temp_queue.popleft())

    return min_val

#example
q = deque([24, 42, 27, 11])
print(find_min(q))