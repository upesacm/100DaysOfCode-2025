from queue import Queue

def queue_size(q):
    return q.qsize()

q1 = Queue()
q1.put(1)
q1.put(2)
q1.put(3)
q1.put(4)
print(queue_size(q1))

q2 = Queue()
q2.put(7)
print(queue_size(q2))
