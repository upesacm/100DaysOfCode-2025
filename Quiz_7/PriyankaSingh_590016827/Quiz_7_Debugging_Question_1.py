def is_queue_palindrome(queue):
    stack = []
    
  
    temp_queue = queue.copy()
    
    while temp_queue:
        element = temp_queue.pop(0)
        stack.append(element)
    
    
    original_queue_copy = queue.copy()

    while original_queue_copy and stack:
        if original_queue_copy.pop(0) != stack.pop():
            return False

    return len(original_queue_copy) == len(stack)
