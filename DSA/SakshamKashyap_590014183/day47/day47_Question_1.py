def insert_rear(queue, element):
    queue.append(element)
    return queue
queue1 = [1, 2]
updated_queue1 = insert_rear(queue1, 3)
print("Insert at Rear:", updated_queue1)