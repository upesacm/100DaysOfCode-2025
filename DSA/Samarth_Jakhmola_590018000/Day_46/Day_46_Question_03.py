from collections import deque

def merge(Q1, Q2):
    for _ in range(len(Q2)):
        current = Q2.popleft()
        Q1.append(current)
        Q2.append(current)

    return Q1

try:
    Q1 = deque(list(map(int, input("Enter the elements of Queue 1 : ").split())))
    Q2 = deque(list(map(int, input("Enter the elements of Queue 2 : ").split())))
    print(list(merge(Q1, Q2)))
except:
    print("Invalid input. Please try with a valid input.")
