from collections import deque

def maximum_element(queue):
    maximum = 0

    for _ in range(len(queue)):
        current = queue.popleft()
        maximum = max(maximum, current)
        queue.append(current)

    return maximum

try:
    queue = deque(list(map(int, input("Enter the elements of the array : ").split())))
    print(maximum_element(queue))
except:
    print("Invalid input. Please try with a valid input.")
