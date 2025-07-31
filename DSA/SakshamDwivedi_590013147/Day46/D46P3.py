def enqueue(queue, num):
    queue.append(num)

def deque(queue):
    if queue:
        return queue.pop(0)
    return None

def merge_queues(q1, q2):
    size2 = len(q2)
    for i in range(size2):
        val = deque(q2)
        enqueue(q1, val)
    return q1

# Fixed Inputs
q1 = []
q2 = []

for i in [1, 2]:
    enqueue(q1, i)

for i in [3, 4]:
    enqueue(q2, i)

merged = merge_queues(q1, q2)
print("Merged Queue:", merged)
