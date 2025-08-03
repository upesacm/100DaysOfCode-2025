#Use auxiliary data structures to reverse the first k queue elements while maintaining FIFO order for the remaining elements. 
from collections import deque

queue_input = input("Enter queue elements separated by space: ") 
k = int(input("Enter value of k: "))  

queue = deque(map(int, queue_input.split()))

stack = []
for _ in range(k):
    stack.append(queue.popleft())

while stack:
    queue.appendleft(stack.pop())

for _ in range(len(queue) - k):
    queue.append(queue.popleft())

print("Output:")
print(list(queue))
