# 3. Find the Front and Rear of the Queue
# A diagnostic operation to retrieve boundary elements of a queue without altering it — useful for monitoring, status checks, and queue visualization.

# Write a function that returns the front and rear elements of a queue without modifying it. If the queue is empty, return an appropriate message.

# This teaches non-destructive access, queue boundary analysis, and helps in queue status validation in various applications.

# Your task: Retrieve the front and rear of the queue or return an empty message.

# Examples
# Input:

# Queue = [10, 20, 30]
# Output:

# Front: 10, Rear: 30
# Input:

# Queue = []
# Output:

# Queue is empty
from queue import Queue

def front_and_rear(q: Queue):
    if q.empty():
        return "Queue is empty"
    
    temp = Queue()
    front = None
    rear = None

    first = True
    while not q.empty():
        item = q.get()
        if first:
            front = item
            first = False
        rear = item
        temp.put(item)

    while not temp.empty():
        q.put(temp.get())
    
    return f"Front: {front}, Rear: {rear}"