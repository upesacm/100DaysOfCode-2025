from queue import Queue

def find_max_in_queue(q):
    if q.empty():
        print("The queue is empty.")
        return None

    max_val = float('-inf')
    size = q.qsize()

    for _ in range(size):
        element = q.get()

        if isinstance(element, (int, float)):
            if element > max_val:
                max_val = element
        else:
            print(f"Skipping non-numeric element: {element}")

        q.put(element)

    return max_val
