def insert_front(queue, element):
    queue.insert(0, element)
    return queue

# Example usage:
queue = [2, 3, 4]
result = insert_front(queue, 1)
print(result)  
queue1 = [7, 8]
result = insert_front(queue1, 6)
print(result)  