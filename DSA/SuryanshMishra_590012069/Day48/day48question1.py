# 1. Remove All Occurrences of an Element from a Queue
# A problem that demonstrates selective queue modification techniques and teaches element filtering operations using conditional removal algorithms for data cleaning and queue purification processes.

# Given a queue of integers and an integer x, remove all occurrences of x from the queue and return the updated queue. This operation is fundamental in data filtering and queue cleaning where you need to eliminate specific values while preserving the order of remaining elements. The technique requires understanding conditional traversal methods that selectively retain or discard elements based on matching criteria. This concept is essential in data preprocessing, noise removal, and stream filtering where removing unwanted values improves data quality and enables focused processing of relevant information.

# This teaches selective filtering algorithms and conditional queue modification techniques that are essential for data cleaning and efficient element removal operations.

# Your task: Implement conditional queue traversal with selective element retention to remove all instances of the target value while preserving queue order.

# Examples
# Input:

# Queue = [1, 2, 3, 2, 4], x = 2
# Output:

# [1, 3, 4]
# Input:

# Queue = [5, 5, 5], x = 5
# Output:

# []
from queue import Queue

def remove_all_occurrences(q: Queue, x: int) -> Queue:
    temp = Queue()

    while not q.empty():
        item = q.get()
        if item != x:
            temp.put(item)

    return temp
def print_queue(q: Queue):
    temp = Queue()
    while not q.empty():
        item = q.get()
        print(item, end=' ')
        temp.put(item)
    while not temp.empty():
        q.put(temp.get())
    print()