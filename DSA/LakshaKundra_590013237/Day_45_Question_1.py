from queue import Queue

def sum_queue(q):
    total = 0
    size = q.qsize()
    for _ in range(size):
        val = q.get()
        total += val
        q.put(val)
    return total

q1 = Queue()
for i in [1, 2, 3]:
    q1.put(i)
print(sum_queue(q1))

q2 = Queue()
for i in [10, 20, 30]:
    q2.put(i)
print(sum_queue(q2))
