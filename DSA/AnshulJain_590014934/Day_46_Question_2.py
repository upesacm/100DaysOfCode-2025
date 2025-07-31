from collections import deque
q = deque(map(int, input("Enter The Queue:-").split()))
even = 0
odd = 0
for _ in range(len(q)):
    val = q.popleft()
    if val % 2 == 0:
        even += 1
    else:
        odd += 1
    q.append(val)
print(f'Even: {even}, Odd: {odd}')
#for example:
# Input: 3 1 4 1 5
# Output: Even: 1, Odd: 4