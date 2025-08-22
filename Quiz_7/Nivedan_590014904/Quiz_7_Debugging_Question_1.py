def is_queue_palindrome(queue):
    stack = []
    temp_queue = queue.copy()

    while temp_queue:
        element = temp_queue.pop(0)
        stack.append(element)

    while temp_queue and stack:#Here and in the lines below there was the bug.
      #We were using the main queue instead of the temp queue so it was being modified 
      
        if temp_queue.pop(0) != stack.pop():
            return False

    return len(queue) == len(stack)


# Test case that reveals the bug:
test_queue = ["r", "a", "c", "e", "c", "a", "r"]
result = is_queue_palindrome(test_queue)
print(f"Is palindrome: {result}")
print(f"Original queue after check: {test_queue}")
