from collections import deque

def display_queue(q):
    # This works whether q is a deque or a list
    for elem in q:
        print(elem, end=' ')
    print()

# Example:
queue = deque([10, 20, 30])
display_queue(queue) 
queue2 = [5, 15]
display_queue(queue2)  