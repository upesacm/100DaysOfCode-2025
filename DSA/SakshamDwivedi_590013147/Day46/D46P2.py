queue = []

def enqueue(queue, num):
    queue.append(num)

def deque(queue):
    if queue:
        return queue.pop(0)
    return None

def count_even_odd(queue):
    size = len(queue)
    even = 0
    odd = 0

    for i in range(size):
        val = deque(queue)
        if val % 2 == 0:
            even += 1
        else:
            odd += 1
        enqueue(queue, val)

    return even, odd

# Fixed Input
for i in [1, 2, 3, 4, 5]:
    enqueue(queue, i)

even, odd = count_even_odd(queue)
print("Even:", even, ", Odd:", odd)
