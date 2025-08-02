from collections import deque

def remove_occurences(queue, x):
    for _ in range(len(queue)):
        current = queue.popleft()
        if  current == x:
            continue
        else:
            queue.append(current)

    return list(queue)

try:
    queue = []
    elements = list(input("Enter the elements of the queue : ").split())
    for i in elements:
        if i.isdigit():
            queue.append(int(i))
        else:
            queue.append(i)
    x = input("Enter the value of x : ")
    if x.isdigit():
        print(remove_occurences(deque(queue), int(x)))
    else:
        print(remove_occurences(deque(queue), x))
except:
    print("Invalid input. Please try with a valid input.")
