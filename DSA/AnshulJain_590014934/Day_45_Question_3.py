from collections import deque
queue = deque(map(int, input("Enter The number:").split()))#taking input from the user 
maximum = queue[0]
for _ in range(len(queue)):
    element = queue.popleft()
    if element > maximum:
        maximum = element
    queue.append(element)
print(maximum)
#for example:
# Input: 1 2 3 4
# Output: 4