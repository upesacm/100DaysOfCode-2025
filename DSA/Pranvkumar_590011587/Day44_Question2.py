def size_of_queue(q):
    return len(q)

# Example:
queue = [1, 2, 3, 4]
print(size_of_queue(queue))  # Output: 4

queue2 = [7]
print(size_of_queue(queue2))  # Output: 1

def size_of_queue_iterative(q):
    count = 0
    for _ in q:
        count += 1
    return count