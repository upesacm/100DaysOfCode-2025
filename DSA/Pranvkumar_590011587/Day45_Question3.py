from collections import deque

def max_in_queue(q):
    if not q:
        return None
    temp = deque()
    maximum = float('-inf')
    while q:
        item = q.popleft()
        maximum = max(maximum, item)
        temp.append(item)
    # Restore original queue
    while temp:
        q.append(temp.popleft())
    return maximum

# Example
q = deque([3, 5, 1, 2])
print(max_in_queue(q)) 