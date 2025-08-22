def insert_front(queue, element):
    queue.insert(0, element)
    return queue

queue2 = [2, 3, 4]
updated_queue2 = insert_front(queue2, 1)
print("Insert at Front:", updated_queue2)