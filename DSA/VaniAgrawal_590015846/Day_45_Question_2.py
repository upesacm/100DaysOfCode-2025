#: Implement systematic queue comparison using parallel element traversal to verify complete structural and content equality between queue instances.
from collections import deque

input_q1 = input("Enter elements of Queue 1 separated by spaces: ")
input_q2 = input("Enter elements of Queue 2 separated by spaces: ")

queue1 = deque(map(int, input_q1.strip().split()))
queue2 = deque(map(int, input_q2.strip().split()))

are_equal = True
temp1 = deque()
temp2 = deque()

while queue1 and queue2:
    val1 = queue1.popleft()
    val2 = queue2.popleft()
    temp1.append(val1)
    temp2.append(val2)
    if val1 != val2:
        are_equal = False

if queue1 or queue2:
    are_equal = False

queue1 = temp1
queue2 = temp2

print("Output:")
print("Yes" if are_equal else "No")
