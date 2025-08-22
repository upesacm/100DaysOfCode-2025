from collections import deque

# Function to insert element at rear
def insert_rear(queue, element):
    queue.append(element)
    return list(queue)

# Function to insert element at front
def insert_front(queue, element):
    queue.appendleft(element)
    return list(queue)

# Function to find front and rear of the queue
def front_and_rear(queue):
    if not queue:
        return "Queue is empty."
    else:
        return f"Front: {queue[0]}, Rear: {queue[-1]}"

# Example Usage
q1 = deque([1, 2])
print("Insert at Rear:", insert_rear(q1, 3))  # [1, 2, 3]

q2 = deque([2, 3, 4])
print("Insert at Front:", insert_front(q2, 1))  # [1, 2, 3, 4]

q3 = deque([10, 20, 30])
print("Front and Rear:", front_and_rear(q3))  # Front: 10, Rear: 30

q4 = deque([])
print("Front and Rear:", front_and_rear(q4))  # Queue is empty.
