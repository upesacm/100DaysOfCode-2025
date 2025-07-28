from collections import deque
n = int(input("Enter value of n: "))# taking input from the user
queue = deque()
queue.append("1")
result = []
for _ in range(n):
    front = queue.popleft()
    result.append(front)
    queue.append(front + "0")
    queue.append(front + "1")
print(result)
#for example:
#input: 5
#output: ['1', '10', '11', '100', '101']
