def is_queue_palindrome(queue):
    stack = []
    temp_queue = queue.copy()

    while temp_queue:
        element = temp_queue.pop(0)
        stack.append(element)

    while temp_queue and stack: #We were also using the orginal queue here instead of the temp queue 
        if temp_queue.pop(0) != stack.pop():
          #Here we were previously using the original queue instead of the temp one
            return False

    return len(queue) == len(stack)


# Test case that reveals the bug:
test_queue = ["r", "a", "c", "e", "c", "a", "r"]
result = is_queue_palindrome(test_queue)
print(f"Is palindrome: {result}")
print(f"Original queue after check: {test_queue}")
