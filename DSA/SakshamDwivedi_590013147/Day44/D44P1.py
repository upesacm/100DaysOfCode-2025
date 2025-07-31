queue = []

def enqueue(queue, num):
    return queue.append(num)

def deque(queue):
    if queue:
        return queue.pop(0)
    return None

def peek(queue):
    if queue:
        return queue[0]
    return None

def display(queue):
    size = len(queue)
    for i in range(size):
        val = deque(queue)
        print(val, end=' ')
        enqueue(queue, val)

#Fixed Input
for i in [10, 20, 30]:
    enqueue(queue, i)

display(queue)
