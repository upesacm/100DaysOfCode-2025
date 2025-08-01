# 1. Insert Element at Rear of Queue
# A basic yet essential operation in queue handling that introduces the concept of enqueueing elements at the rear for standard FIFO behavior. This builds a strong foundation in linear data structure manipulation.

# Write a function that inserts a given element at the rear of a queue and returns the updated queue.

# This teaches rear insertion, queue dynamics, and is fundamental to real-time systems, task scheduling, and data buffering.

# Your task: Insert an element at the end of a queue and return the updated queue.

# Examples
# Input:

# Queue = [1, 2], Insert = 3
# Output:

# [1, 2, 3]
from queue import Queue

def insert_rear(q: Queue, value: int) -> Queue:
    q.put(value)
    return q

def print_queue(q: Queue):
    temp = Queue()
    while not q.empty():
        item = q.get()
        print(item, end=' ')
        temp.put(item)
    while not temp.empty():
        q.put(temp.get())
    print()
