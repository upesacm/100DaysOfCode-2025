def front_and_rear(queue):
    if not queue:
        return "Queue is empty"
    return f"Front: {queue[0]}, Rear: {queue[-1]}"

# Example usage:
queue = [10, 20, 30]
result = front_and_rear(queue)
print(result)  
queue1 = []
result = front_and_rear(queue1)
print(result)  