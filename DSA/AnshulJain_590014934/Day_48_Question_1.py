from collections import deque
queue = deque(map(int, input("Enter the queue elements separated by space: ").split()))
x = int(input("Enter the element to remove: "))
updated_queue = deque()
for elem in queue:
    if elem != x:
        updated_queue.append(elem)
print(list(updated_queue))
#for example:
# Input: Enter the queue elements separated by space: 1 2 3 4 5q
# Input: Enter the element to remove: 3
# Output: [1, 2, 4, 5]