def front_and_rear(queue):
    if not queue:
        return "Queue is empty"
    return f"Front: {queue[0]}, Rear: {queue[-1]}"

queue3 = [10, 20, 30]
result = front_and_rear(queue3)
print("Front and Rear:", result) 

# Check empty queue for front_and_rear
empty_queue = []
empty_result = front_and_rear(empty_queue)
print("Empty queue check:", empty_result)