from collections import deque

def merge_queues_alternately(q1, q2):
    result = deque()
    
    #alternate until one queue runs out
    while q1 and q2:
        result.append(q1.popleft())
        result.append(q2.popleft())

    #append any remaining elements
    result.extend(q1)
    result.extend(q2)

    return result

#test case
queue1 = deque([1, 3, 5])
queue2 = deque([2, 4])
merged = merge_queues_alternately(queue1, queue2)
print(f"Merged queue: {list(merged)}")
