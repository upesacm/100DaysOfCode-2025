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

for i in [1, 2, 3, 4]:
    enqueue(queue, i)

print(size(queue))
