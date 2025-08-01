from queue import Queue

def count_even_odd(q):
    size = q.qsize()
    even_count = 0
    odd_count = 0

    for _ in range(size):
        element = q.get()
        if element % 2 == 0:
            even_count += 1
        else:
            odd_count += 1
        q.put(element)

    return even_count, odd_count
