from collections import deque

def count_occurences(queue):
    frequency = {}

    for _ in range(len(queue)):
        current = queue.popleft()
        if current in frequency:
            frequency[current] += 1
        else:
            frequency[current] = 1
        queue.append(current)

    return frequency

queue = []
elements = list(input("Enter the elements of the queue : ").split())
for i in elements:
    if i.isdigit():
        queue.append(int(i))
    else:
        queue.append(i)
print(count_occurences(deque(queue)))
