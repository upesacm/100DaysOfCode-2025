def insert_front(queue, element):
    queue.insert(0, element)
    return queue

print(insert_front([2, 3, 4], 1))    # Output: [1, 2, 3, 4]
print(insert_front([7, 8], 6))       # Output: [6, 7, 8]
