from collections import deque

queue = deque(map(int, input("Enter the Queue").split()))# taking input from the user 
temp = deque()

while queue:
    val = queue.popleft()
    print(val, end=' ')
    temp.append(val)

while temp:
    queue.append(temp.popleft())
#for example:
# Input: 1 2 3 4 5
# Output: 1 2 3 4 5