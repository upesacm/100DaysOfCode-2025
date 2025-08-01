def insert_rear(queue, element):
    queue.append(element)
    return queue

print(insert_rear([1, 2], 3))      # Output: [1, 2, 3]
print(insert_rear([4, 5], 6))      # Output: [4, 5, 6]
