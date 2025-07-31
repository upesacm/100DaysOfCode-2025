from queue import Queue

def are_queues_equal(q1, q2):
    if q1.qsize() != q2.qsize():
        return False

    size = q1.qsize()
    equal = True

    for _ in range(size):
        e1 = q1.get()
        e2 = q2.get()

        if e1 != e2:
            equal = False

        q1.put(e1)
        q2.put(e2)

    return equal
