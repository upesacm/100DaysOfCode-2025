from collections import deque

def insert_at_front(queue, element):
    dq = deque(queue)
    if element.isdigit():
        dq.appendleft(int(element))
    else:
        dq.appendleft(element)
    return list(dq)

try:
    queue = []
    elements = list(input("Enter the elements of the queue : ").split())
    for i in elements:
        if i.isdigit():
            queue.append(int(i))
        else:
            queue.append(i)
    element = input("Enter the element to be inserted : ")
    print(insert_at_front(queue, element))
except:
    print("Invalid input. Please try with a valid input.")
