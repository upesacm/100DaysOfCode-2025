from queue import Queue

def sum_queue_elements(q):
    if q.empty():
        print("The queue is empty.")
        return 0

    total_sum = 0
    size = q.qsize()

    for _ in range(size):
        element = q.get()

        if not isinstance(element, (int, float)):
            print(f"Skipping non-numeric element: {element}")
            q.put(element)
            continue

        total_sum += element
        q.put(element)

    return total_sum

q = Queue()
q.put(5)
q.put(10)
q.put("hello")
q.put(15)
q.put(20)

result = sum_queue_elements(q)
print("Sum of numeric elements in the queue:", result)
