from queue import Queue

def find_min_in_queue(q):
    size = q.qsize()
    min_value = float('inf')

    for _ in range(size):
        element = q.get()
        if element < min_value:
            min_value = element
        q.put(element)

    return min_value
