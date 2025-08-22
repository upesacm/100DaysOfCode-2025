from collections import deque, defaultdict
queue = deque(map(int, input("Enter the queue elements separated by space: ").split()))
frequency = defaultdict(int)
for elem in queue:
    frequency[elem] += 1
print(dict(frequency))
#for example:
# Input: Enter the queue elements separated by space: 1 2 2 3 4 4 4
# Output: {1: 1, 2: 2, 3: 1, 4: 3}