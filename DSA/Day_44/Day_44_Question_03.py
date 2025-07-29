from collections import deque

def check_empty_queue(queue):
    return len(queue) == 0

try:
    queue = deque(list(map(int, input("Enter the elements of the queue : ").split())))
    print(check_empty_queue(queue))
except:
    print("Invalid input. Please try with a valid input.")
