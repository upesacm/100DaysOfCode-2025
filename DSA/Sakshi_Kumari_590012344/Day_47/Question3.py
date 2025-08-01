def front_and_rear(queue):
    if not queue:
        return "The queue is empty."
    front = queue[0]
    rear = queue[-1]
    return (front, rear)
