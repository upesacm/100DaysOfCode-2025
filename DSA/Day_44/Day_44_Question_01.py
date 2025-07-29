from collections import deque 

def display(queue):
    for _ in range(len(queue)):
        front = queue.popleft()
        print(front, end = " ")
        queue.append(front)

try:
    queue = deque(list(map(int, input("Enter the elements of queue : ").split())))
    display(queue)
except:
    print("Invalid input. Please try with a valid input.")
