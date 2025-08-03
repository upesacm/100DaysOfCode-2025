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

def count_occurrences(queue):
    freq = {}
    size = len(queue)
    for i in range(size):
        val = deque(queue)
        if val in freq:
            freq[val] += 1
        else:
            freq[val] = 1
        enqueue(queue, val)
    return freq

#Fixed Input
for i in [1, 2, 2, 3, 1, 1]:
    enqueue(queue, i)

result = count_occurrences(queue)
print(result)
