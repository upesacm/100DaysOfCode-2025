# Implement queue-based binary number generation by systematically expanding each number with '0' and '1' extensions using FIFO processing.
from collections import deque

n = int(input("Enter the value of n: "))

queue = deque()
queue.append("1")

result = []

for _ in range(n):
    front = queue.popleft()
    result.append(front)
    queue.append(front + "0")
    queue.append(front + "1")

print(result)
