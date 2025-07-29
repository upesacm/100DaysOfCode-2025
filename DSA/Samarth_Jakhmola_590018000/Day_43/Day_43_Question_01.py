from collections import deque

def reverse_first_k_elements(queue, k):
    if k > len(queue) or k < 0:    # invalid input
        return queue
    
    stack = []

    # Step 1 : Dequeue first k elements and push them to stack
    for _ in range(k):
        stack.append(queue.popleft())

    # Step 2 : Enqueue elements from the stack back to queue
    while stack:
        queue.append(stack.pop())

    # Step 3 : Move the remaining (n-k) elements to the back of the queue
    size = len(queue)
    for _ in range(size - k):
        queue.append(queue.popleft())

    return queue

try:
    queue = deque(list(map(int, input("Enter the elements of the queue : ").split())))
    k = int(input("Enter the value of k : "))
    print(list(reverse_first_k_elements(queue, k)))
except: 
    print("Invalid input. Please try with a valid input.")
