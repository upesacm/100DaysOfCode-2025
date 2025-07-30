from collections import deque

user_input = input("Enter the queue:").strip()

if user_input == '[]' or user_input == '':
    queue = deque()
else:
    user_input = user_input.replace('[', '').replace(']', '')
    queue = deque(map(int, user_input.split(',')))

print(len(queue) == 0)
# for example:
# Input: [1, 2, 3, 4, 5]
# Output: False