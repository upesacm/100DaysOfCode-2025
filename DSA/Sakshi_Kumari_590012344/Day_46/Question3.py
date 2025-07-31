from queue import Queue

def merge_queues(q1, q2):
    merged = Queue()

    while not q1.empty():
        merged.put(q1.get())

    while not q2.empty():
        merged.put(q2.get())

    return merged

