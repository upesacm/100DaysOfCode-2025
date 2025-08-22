def merge_queues_alternately(q1, q2):
    result = deque()
    while q1 and q2:  # Alternate until one queue is empty
        result.append(q1.popleft())
        result.append(q2.popleft())
    # Append remaining elements from the non-empty queue
    result.extend(q1)
    result.extend(q2)
    return result

queue1 = deque([1, 3, 5])
queue2 = deque([2])
merged = merge_queues_alternately(queue1, queue2)
print(f"Merged queue: {list(merged)}")  # Output: [1, 2, 3, 5] (correct)
