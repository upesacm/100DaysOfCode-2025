from collections import deque

def size(queue):
    return len(queue)

try:
    queue = deque(list(map(int, input("Enter the elements of the queue : ").split())))
    print(size(queue))
except:
    print("Invalid input. Please try with a valid input.")
