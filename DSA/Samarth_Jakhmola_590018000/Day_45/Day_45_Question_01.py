from collections import deque

def sum_of_elements(queue):
    sum = 0
    for _ in range(len(queue)):
        front = queue.popleft()
        sum += front
        queue.append(front)

    return sum

try:
    queue = deque(list(map(int, input("Enter the elements of the queue : ").split())))
    print(sum_of_elements(queue))
except:
    print("Invalid input. Please try with a valid input.")
