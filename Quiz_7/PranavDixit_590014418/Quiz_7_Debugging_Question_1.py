"""
QUEUE PALINDROME CHECKER BUG

1. Identify the specific line(s) causing the bug:
   - The bug is caused by: `queue.pop(0)` inside `while queue and stack:` loop.

2. Why this causes incorrect behavior:
   - Because it removes elements from the original input queue, modifying (destroying) the user's data. Also, it means the input queue is empty after the function call, which can lead to confusing bugs if the queue is used again.

CORRECTED CODE BELOW:
"""

def is_queue_palindrome(queue):
    # Using a copy so original queue is not modified
    stack = []
    temp_queue = queue.copy()

    # Fill the stack with elements from the copied queue
    for elem in temp_queue:
        stack.append(elem)

    # Compare queue (original), but do NOT modify it
    # Instead, iterate by index for comparison
    n = len(queue)
    for i in range(n):
        if queue[i] != stack.pop():
            return False

    return True

# Test case
test_queue = ["r", "a", "c", "e", "c", "a", "r"]
result = is_queue_palindrome(test_queue)
print(f"Is palindrome: {result}")
print(f"Original queue after check: {test_queue}")
