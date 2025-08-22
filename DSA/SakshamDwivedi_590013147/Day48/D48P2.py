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

def all_unique(queue):
    size = len(queue)
    is_unique = True

    for i in range(size):
        current = deque(queue)
        enqueue(queue, current)
        for j in range(size - 1):
            val = deque(queue)
            if val == current:
                is_unique = False
            enqueue(queue, val)

        if not is_unique:
            break

    return is_unique

#Fixed Input
for i in [1, 2, 3, 4]:
    enqueue(queue, i)

print(all_unique(queue))  # Output: True
