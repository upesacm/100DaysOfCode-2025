import queue
q = queue.Queue()
q.put(10)
q.put(20)
q.put(30)
def queue_size(q):
    return q.qsize()
print("Size of queue:", queue_size(q))
