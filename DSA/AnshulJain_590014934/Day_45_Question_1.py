from collections import deque
queue = deque(map(int, input("Enter the number:").split()))#Taking input from user
total_sum = 0
for _ in range(len(queue)):
    element = queue.popleft()
    total_sum += element
    queue.append(element)
print(total_sum)
#for example:
# Input: 1 2 3 4
# Output: 10