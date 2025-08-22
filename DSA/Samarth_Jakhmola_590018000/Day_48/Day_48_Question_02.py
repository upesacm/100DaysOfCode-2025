from collections import deque

def unique_elements(queue):
    seen = set()
    temp_queue = deque()
    unique = True
    
    while queue:
        current = queue.popleft()
        if current in seen:
            unique = False
        seen.add(current)
        temp_queue.append(current)

    # Restoring the original queue
    while temp_queue:
        queue.append(temp_queue.popleft())

    return unique
 
try:
    queue = []
    elements = list(input("Enter the elements of the queue : ").split())
    for i in elements:
        if i.isdigit():
            queue.append(int(i))
        else:
            queue.append(i)
    print(unique_elements(deque(queue)))
except:
    print("Invalid input. Please try with a valid input.")
