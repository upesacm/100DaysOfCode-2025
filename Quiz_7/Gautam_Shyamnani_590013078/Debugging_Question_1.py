def is_queue_palindrome(queue):
    stack = []
    copy_queue = queue.copy()  

    
    for element in copy_queue:
        stack.append(element)

    
    while copy_queue and stack:
        if copy_queue.pop(0) != stack.pop():
            return False

    return True



test_queue = ["r", "a", "c", "e", "c", "a", "r"]
result = is_queue_palindrome(test_queue)


print(f"Is palindrome: {result}")
print(f"Original queue after check: {test_queue}")
