from collections import deque
q1 = deque(map(int, input("Enetr the Queue 1:").split()))
q2 = deque(map(int, input("Enter The Queue 2:").split()))
identical = True
if len(q1) != len(q2):
    identical = False
else:
    for _ in range(len(q1)):
        e1 = q1.popleft()
        e2 = q2.popleft()
        if e1 != e2:
            identical = False
        q1.append(e1)
        q2.append(e2)
print("Yes" if identical else "No")
#for example:
# Input: 1 2 3 4
# Input: 1 2 3 4
# Output: Yes