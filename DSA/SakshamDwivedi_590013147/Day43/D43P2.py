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

def generate_binary(n):
    result = []
    q = []
    enqueue(q, "1")

    for i in range(n):
        curr = deque(q)
        enqueue(result, curr)

        enqueue(q, curr + "0")
        enqueue(q, curr + "1")

    return result

#Fixed Input
print(generate_binary(5))
