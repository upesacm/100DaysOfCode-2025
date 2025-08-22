def front_rear(queue):
    if not queue:
        return "Queue is empty"
    return f"Front: {queue[0]}, Rear: {queue[-1]}"

print(front_rear([10, 20, 30]))   # Output: Front: 10, Rear: 30
print(front_rear([]))             # Output: Queue is empty
