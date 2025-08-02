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

def remove_occurrences(queue, x):
    size = len(queue)
    for i in range(size):
        val = deque(queue)
        if val != x:
            enqueue(queue, val)
    return queue

#Fixed Input
for i in [1, 2, 3, 2, 4]:
    enqueue(queue, i)

remove_occurrences(queue, 2)
print(display(queue))
