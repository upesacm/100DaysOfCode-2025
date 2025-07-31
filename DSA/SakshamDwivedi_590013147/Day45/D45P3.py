def enqueue(queue, num):
    return queue.append(num)

def deque(queue):
    if queue:
        return queue.pop(0)
    return None

def display(queue):
    return queue

def max_in_queue(queue):
    if not queue:
        return None

    size = len(queue)
    max_val = float('-inf')

    for i in range(size):
        val = deque(queue)
        max_val = max(max_val, val)
        enqueue(queue, val)

    return max_val

#Fixed Input
queue = []
for num in [3, 5, 1, 2]:
    enqueue(queue, num)

print(max_in_queue(queue))
print(display(queue))
