from collections import deque

def merge_queues_alternately(q1, q2):
    result = deque()

    # Loop continues as long as either queue has elements
    while q1 or q2:
        if q1:
            result.append(q1.popleft())  # take from q1 if available
        if q2:
            result.append(q2.popleft())  # take from q2 if available

    return result

# Test case:
queue1 = deque([1, 3, 5])
queue2 = deque([2, 4])
merged = merge_queues_alternately(queue1, queue2)
print(f"Merged queue: {list(merged)}")
