from collections import deque
q = deque(map(int, input("Enter The Queue:").split()))#Taking input from the user 
min_val = float('inf')
for _ in range(len(q)):
    val = q.popleft()
    if val < min_val:
        min_val = val
    q.append(val)
print(min_val)
#foe example:
# Input: 3 1 4 1 5
# Output: 1