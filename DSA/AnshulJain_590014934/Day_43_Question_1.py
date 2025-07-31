from collections import deque

queue = deque(map(int, input("Enter queue elements separated by space: ").split()))
k = int(input("Enter value of k: "))
stack = []
for _ in range(k):
    stack.append(queue.popleft())
while stack:
    queue.append(stack.pop())
for _ in range(len(queue) - k):
    queue.append(queue.popleft())
print("Queue after reversing first k elements:")
print(*queue)
#for example:
#input: 1 2 3 4 5
    #k:3
#output: 3 2 1 4 5
