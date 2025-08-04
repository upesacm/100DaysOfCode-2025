# BUG:
# - The line `queue.pop(0)` modifies the original queue, so it's no longer preserved.
# - The final line `return len(queue) == len(stack)` is unnecessary and can give wrong results.

# WHY THIS CAUSES INCORRECT BEHAVIOR:
# - The queue is altered during checking, so it's no longer reusable afterward.
# - The return condition doesn't actually confirm palindrome—it just checks queue and stack are both empty.

# FIX:
# - Use a temporary copy of the queue for both comparison and preservation.
# - Return False immediately on mismatch, True at the end if all matched.

def is_queue_palindrome(queue):
    stack = []
    temp_queue = queue.copy()  # Preserve original queue

    for item in temp_queue:
        stack.append(item)  # Build reverse using stack

    for item in temp_queue:
        if item != stack.pop():
            return False  # Mismatch found → not a palindrome

    return True  # All matched

# Test case that now works correctly
test_queue = ["r", "a", "c", "e", "c", "a", "r"]
result = is_queue_palindrome(test_queue)
print(f"Is palindrome: {result}")  # Output: True
print(f"Original queue after check: {test_queue}")  # Queue remains unchanged