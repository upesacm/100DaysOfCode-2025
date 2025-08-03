from collections import deque

def reverse_k_elements(q, k):
    stack = []
    queue = deque(q)
    # Step 1: Push first k elements into a stack
    for _ in range(k):
        stack.append(queue.popleft())
    # Step 2: Enqueue stack contents back to queue
    while stack:
        queue.append(stack.pop())
    # Step 3: Move the rest to back to maintain original order
    for _ in range(len(queue) - k):
        queue.append(queue.popleft())
    return list(queue)

# Examples:
print(reverse_k_elements([1, 2, 3, 4, 5], 3))   
print(reverse_k_elements([10, 20, 30], 2))       