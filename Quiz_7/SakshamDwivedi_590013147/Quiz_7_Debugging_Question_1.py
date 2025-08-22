def is_queue_palindrome(queue):
    stack = []
    temp_queue = queue.copy()

    while temp_queue:
        element = temp_queue.pop(0)
        stack.append(element)
        
    temp_queue = queue.copy() #This line is required, otherwise the original queue is modified.
    while queue and stack:
        if temp_queue.pop(0) != stack.pop(): #Here we need to pop from temp_queue otherwise the original queue will be empty
            return False

    return True #len(queue) == len(stack), this isn't required if above loop completes


# Test case that reveals the bug:
test_queue = ["r", "a", "c", "e", "c", "a", "r"]
result = is_queue_palindrome(test_queue)
print(f"Is palindrome: {result}")
print(f"Original queue after check: {test_queue}")
