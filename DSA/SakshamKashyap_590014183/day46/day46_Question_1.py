def find_min_in_queue(queue):
    if not queue:
        raise ValueError("Queue is empty")
    
    # Initialize min_val to the first element
    min_val = queue[0]
    
    # Traverse and update min_val
    for item in queue:
        if item < min_val:
            min_val = item
    
    return min_val

q1 = [4, 2, 7, 1]
print(find_min_in_queue(q1))  

q2 = [9, 3]
print(find_min_in_queue(q2))   