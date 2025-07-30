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

def size(queue):
    return len(queue)

def is_empty(queue):
    return len(queue) == 0

#Fixed Input
print(is_empty(queue))

enqueue(queue, 5)
print(is_empty(queue))
