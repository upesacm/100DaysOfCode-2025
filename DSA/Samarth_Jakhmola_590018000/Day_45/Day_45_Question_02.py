from collections import deque

def compare_queues(queue1, queue2):
    if len(queue1) != len(queue2):
        return "No"
    
    result = "Yes"
    
    for _ in range(len(queue1)):
        front1 = queue1.popleft()
        front2 = queue2.popleft()

        if front1 != front2:
            result = "No"

        queue1.append(front1)
        queue2.append(front2)

    return result

try:
    queue1 = deque(list(map(int, input("Enter the elements of queue 1 : ").split())))
    queue2 = deque(list(map(int, input("Enter the elements of queue 2 : ").split())))
    print(compare_queues(queue1, queue2))
except:
    print("Invalid input. Please try with a valid input.")
