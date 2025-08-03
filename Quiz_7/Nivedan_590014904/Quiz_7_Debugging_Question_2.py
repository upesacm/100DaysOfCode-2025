from collections import deque


def merge_queues_alternately(q1, q2):
    result = deque()

    while q1 or q2:
        if q1:
            result.append(q1.popleft())
        if q2:
            result.append(q2.popleft())

    return result


# Test case:
queue1 = deque([1, 3, 5])
queue2 = deque([2, 4])
merged = merge_queues_alternately(queue1, queue2)
print(f"Merged queue: {list(merged)}")
#The code works just fine tho
