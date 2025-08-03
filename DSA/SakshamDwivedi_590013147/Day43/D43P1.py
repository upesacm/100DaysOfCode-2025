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

def reverse_k(queue, k):
    n = len(queue)

    def reverse(k):
        if k <= 0:
            return
        val = deque(queue)
        reverse(k - 1)
        enqueue(queue, val)

    reverse(k)

    for i in range(n - k):
        enqueue(queue, deque(queue))
    return queue

#Fixed Input
queue = [1,2,3,4,5]
print(reverse_k(queue, 3))
