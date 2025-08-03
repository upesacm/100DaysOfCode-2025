queue = []

def enqueue(queue, num):
    queue.append(num)

def peek_front(queue):
    if queue:
        return queue[0]
    return None

def peek_rear(queue):
    if queue:
        return queue[-1]
    return None

def display_front_rear(queue):
    if not queue:
        print("Queue is empty")
    else:
        print("Front:", peek_front(queue), ", Rear:", peek_rear(queue))

# Fixed Input
queue = [10, 20, 30]
display_front_rear(queue)
