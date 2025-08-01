def find_front_rear(queue):
    if not queue:
        return "Queue is Empty"
    return f"Front:{queue[0]} , Rear:{queue[-1]}"

#example
print(find_front_rear([41,42,43,45,46,47,48]))