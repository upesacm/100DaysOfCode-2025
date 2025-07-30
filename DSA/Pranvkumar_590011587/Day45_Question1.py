from collections import deque

def sum_queue(q):
    total = 0
    temp = deque()
    while q:
        item = q.popleft()
        total += item
        temp.append(item)
    # Restore original queue
    while temp:
        q.append(temp.popleft())
    return total

# Example
q = deque([1, 2, 3])
print(sum_queue(q))  