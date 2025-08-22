def insert_rear(queue, element):
    queue.append(element)
    return queue

# Example usage:
queue = [1, 2]
result = insert_rear(queue, 3)
print(result)   
queue1 = [4, 5]
result = insert_rear(queue1, 6)
print(result)   