from queue import Queue

def is_queue_empty(q):
    return q.empty()

q1 = Queue()
print(is_queue_empty(q1))

q2 = Queue()
q2.put(1)
q2.put(2)
print(is_queue_empty(q2))
