def is_queue_palindrome(queue):
    stack = []
    
    # Make a copy of the original queue to avoid modifying it
    temp_queue = queue.copy()

    # Push all elements from the temp_queue into the stack
    while temp_queue:
        element = temp_queue.pop(0)  # dequeue from front
        stack.append(element)        # push onto stack

    # Create another copy for comparison so that original queue remains untouched
    temp_queue2 = queue.copy()

    # Compare elements from the front of the queue and top of the stack
    while temp_queue2 and stack:
        if temp_queue2.pop(0) != stack.pop():
            return False

    # If all matched, it's a palindrome
    return True


# Original test case
test_queue = ["r", "a", "c", "e", "c", "a", "r"]
result = is_queue_palindrome(test_queue)

print(f"Is palindrome: {result}")
print(f"Original queue after check: {test_queue}")
