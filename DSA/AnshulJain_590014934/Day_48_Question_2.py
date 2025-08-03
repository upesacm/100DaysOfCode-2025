from collections import deque
queue = deque(map(int, input("Enter the queue elements separated by space: ").split()))
seen = set()
is_unique = True
for elem in queue:
    if elem in seen:
        is_unique = False
        break
    seen.add(elem)
print(is_unique)
#for example:
# Input: Enter the queue elements separated by space: 1 2 3 4 5
# Output: True
