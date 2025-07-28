from collections import deque
def is_queue_palindrome(q):
    queue = deque(q)
    stack = []
    size = len(queue)   # Push all elements to stack
    for elem in queue:
        stack.append(elem)
# Compare
    for i in range(size):
        if queue[i] != stack.pop():
            return "No"
    return "Yes"

# Examples:
print(is_queue_palindrome(['r', 'a', 'c', 'e', 'c', 'a', 'r'])) 
print(is_queue_palindrome(['a', 'b', 'c']))                 