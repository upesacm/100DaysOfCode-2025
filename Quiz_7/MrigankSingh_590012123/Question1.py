def is_queue_palindrome(queue):
    stack = []
    temp_queue = queue.copy()  # Preserve original queue

    # Push all elements to stack (reversing order)
    while temp_queue:
        stack.append(temp_queue.pop(0))

    # Compare original queue (using another copy) with stack
    compare_queue = queue.copy()
    while compare_queue and stack:
        if compare_queue.pop(0) != stack.pop():
            return False

    return True  # No need for length check; loop ensures full comparison

# Test case that reveals the bug:
test_queue = ["r", "a", "c", "e", "c", "a", "r"]
result = is_queue_palindrome(test_queue)
print(f"Is palindrome: {result}")
print(f"Original queue after check: {test_queue}")
