queue = []

def enqueue(queue, num):
    queue.append(num)

def dequeue(queue):
    if queue:
        return queue.pop(0)
    return None

def insert_front(queue, num):
    enqueue(queue, num)
    size = len(queue)
    for i in range(size - 1):
        enqueue(queue, dequeue(queue))

def display(queue):
    print(queue)

# Fixed Input
queue = [2, 3, 4]
x = 1
insert_front(queue, x)
display(queue)
