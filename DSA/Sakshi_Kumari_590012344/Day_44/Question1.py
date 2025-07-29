import queue

def display_queue(q):
    if q.empty():
        print("Queue is empty")
        return

    temp_queue = queue.Queue()

    print("Queue contents (Front to Rear):", end=" ")
    while not q.empty():
        item = q.get()
        print(item, end=" ")
        temp_queue.put(item)

    print()

    while not temp_queue.empty():
        q.put(temp_queue.get())
