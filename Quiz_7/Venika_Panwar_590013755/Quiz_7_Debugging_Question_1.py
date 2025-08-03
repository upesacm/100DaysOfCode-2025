# Question 1:

# Task 1:
# BUGGY LINE (Original Code):
# Line 11: `if queue.pop(0) != stack.pop():`  -> Modifies original queue.
# Line 15: `return len(queue) == len(stack)` -> Irrelevant final check.

# Task 2:
# WHY THIS CAUSES INCORRECT BEHAVIOR:
# - Line 11 mutates the input queue, so the original data is lost.
# - Line 15 does not validate palindrome logic—just checks both structures are empty.

# FIX:
# - Use a temporary copy of the queue for comparison.
# - Compare elements using the original sequence and a reversed stack.

def is_queue_palindrome(queue):
    """Check whether a queue forms a palindrome without modifying it."""
    stack = []
    temp_queue = queue.copy()  # Preserve original queue

    for item in temp_queue:
        stack.append(item)  # Build reverse using stack

    for item in temp_queue:
        if item != stack.pop():
            return False  # Mismatch → not a palindrome

    return True  # All characters matched

# Test case
test_queue = ["r", "a", "c", "e", "c", "a", "r"]
result = is_queue_palindrome(test_queue)
print(f"Is palindrome: {result}")  #  Output: True
print(f"Original queue after check: {test_queue}")  # Queue preserved
