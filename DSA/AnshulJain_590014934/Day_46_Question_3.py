from collections import deque
q1 = deque(map(int, input("Enter the Queue 1 :").split()))
q2 = deque(map(int, input("Enter The Queue 2:").split()))
for _ in range(len(q2)):
    q1.append(q2.popleft())
print(list(q1))
# for example:
# Input:  queue 1:-1 2 3
# Input: Queue 2:-4 5 6
# Output: [1, 2, 3, 4, 5, 6]
