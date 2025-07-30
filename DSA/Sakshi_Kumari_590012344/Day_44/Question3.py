import queue

q = queue.Queue()

def is_queue_empty(q):
    return q.empty()

print("Is the queue empty?", is_queue_empty(q))  
q.put(10)
print("Is the queue empty?", is_queue_empty(q))  
