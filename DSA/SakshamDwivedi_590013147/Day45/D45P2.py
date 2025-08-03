def enqueue(queue, num):
    return queue.append(num)

def deque(queue):
    if queue:
        return queue.pop(0)
    return None

def display(queue):
    return queue

def are_queues_equal(q1, q2):
    if len(q1) != len(q2):
        return "No"
    
    size = len(q1)
    match = True

    for i in range(size):
        val1 = deque(q1)
        val2 = deque(q2)

        if val1 != val2:
            match = False

        enqueue(q1, val1)
        enqueue(q2, val2)

    return "Yes" if match else "No"

#Fixed Input
Q1 = []
Q2 = []

for i in [1, 2, 3]:
    enqueue(Q1, i)
    enqueue(Q2, i)

print(are_queues_equal(Q1, Q2))
print(display(Q1))
print(display(Q2))
