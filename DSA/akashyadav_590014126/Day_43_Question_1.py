from collections import deque
def reverse_k_elements(queue,k):
    if queue is None or k <= 0 or k > len(queue):
        return queue
    
    stack=[]

    for _ in range(k):
        stack.append(queue.popleft())
    
    while stack:
        queue.append(stack.pop())
    
    for _ in range(len(queue) - k):
        queue.append(queue.popleft())
    
    return list(queue)