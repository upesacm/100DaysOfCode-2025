from queue import Queue

def compare_queues(q1, q2):
    if q1.qsize() != q2.qsize():
        return "No"
    size = q1.qsize()
    equal = True
    for _ in range(size):
        a = q1.get()
        b = q2.get()
        if a != b:
            equal = False
        q1.put(a)
        q2.put(b)
    return "Yes" if equal else "No"

q1 = Queue()
q2 = Queue()
for i in [1, 2, 3]:
    q1.put(i)
for i in [1, 2, 3]:
    q2.put(i)
print(compare_queues(q1, q2))

q3 = Queue()
q4 = Queue()
for i in [1, 2]:
    q3.put(i)
for i in [2, 1]:
    q4.put(i)
print(compare_queues(q3, q4))
