def Reverse_first_k(queue,k):
    if queue is None:
        return
    stack = []
    for i in range(k):
        stack.append(queue.pop(0))
    while stack:
        queue.append(stack.pop())
    for i in range(len(queue)-k):
        queue.append(queue.pop(0))
    return queue
#test Cases
queue = [1, 2, 3, 4, 5]
k = 3
print(Reverse_first_k(queue, k))
        
