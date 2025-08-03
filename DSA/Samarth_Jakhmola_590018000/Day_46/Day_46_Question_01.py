from collections import deque

def minimum_element(queue):
    minimum = float('inf')  # Initializing with a very large number.

    for _ in range(len(queue)):
        current = queue.popleft()
        minimum = min(current, minimum)
        queue.append(current)

    return minimum

try:
    queue = deque(list(map(int, input("Enter the elements of the queue : ").split())))
    print(minimum_element(queue))
except:
    print("Invalid input. Please try with a valid input.")
