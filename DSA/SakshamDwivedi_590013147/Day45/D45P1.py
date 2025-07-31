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
    return queue

def sum_queue(queue):
    total = 0
    size = len(queue)

    for i in range(size):
        val = deque(queue)
        total += val
        enqueue(queue, val)

    return total

#Fixed Input
queue = []
for i in [1, 2, 3]:
    enqueue(queue, num)

print(sum_queue(queue))
print(display(queue))
