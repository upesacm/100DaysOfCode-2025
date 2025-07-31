from queue import Queue

def max_in_queue(q):
    size = q.qsize()
    maximum = float('-inf')
    for _ in range(size):
        val = q.get()
        if val > maximum:
            maximum = val
        q.put(val)
    return maximum

q1 = Queue()
for i in [3, 5, 1, 2]:
    q1.put(i)
print(max_in_queue(q1))

q2 = Queue()
for i in [10, 7, 4]:
    q2.put(i)
print(max_in_queue(q2))
