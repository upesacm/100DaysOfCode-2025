from collections import deque

def remove_occurrences(queue, x):
    new_queue = deque()
    while queue:
        current = queue.popleft()
        if current != x:
            new_queue.append(current)
    return new_queue
