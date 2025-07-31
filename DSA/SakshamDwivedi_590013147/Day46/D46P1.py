queue = []

def enqueue(queue, num):
    queue.append(num)

def deque(queue):
    if queue:
        return queue.pop(0)
    return None

def find_min(queue):
    size = len(queue)
    min_val = float('inf')

    for i in range(size):
        val = deque(queue)
        if val < min_val:
            min_val = val
        enqueue(queue, val)

    return min_val

# Fixed Input
for i in [4, 2, 7, 1]:
    enqueue(queue, i)

print("Minimum element :", find_min(queue))
