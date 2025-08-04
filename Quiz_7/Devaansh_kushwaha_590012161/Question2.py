from collections import deque

def merge_queues_alternately(q1, q2):
    result = deque()

    while q1 and q2:
        result.append(q1.popleft())
        result.append(q2.popleft())

    # After the loop, one of the queues (or both) might be empty.
    # Append any remaining elements from q1.
    while q1:
        result.append(q1.popleft())
    
    # Append any remaining elements from q2.
    while q2:
        result.append(q2.popleft())

    return result

queue1 = deque([1, 3, 5])
queue2 = deque([2, 4])
merged = merge_queues_alternately(queue1, queue2)
print(f"Merged queue: {list(merged)}")

queue3 = deque([1, 2, 3])
queue4 = deque([4, 5, 6, 7, 8])
merged2 = merge_queues_alternately(queue3, queue4)
print(f"Merged queue: {list(merged2)}")

queue5 = deque([10, 20, 30, 40])
queue6 = deque([1, 2])
merged3 = merge_queues_alternately(queue5, queue6)
print(f"Merged queue: {list(merged3)}")
