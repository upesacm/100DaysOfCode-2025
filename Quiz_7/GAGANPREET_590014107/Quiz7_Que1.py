#1. Identify the specific line(s) causing the bug
#--   while queue and stack:
#      if queue.pop(0) != stack.pop():
#        return False

#2. Why this causes incorrect behavior:
#-- This line modifies the original queue by using queue.pop(0).
#   The function is supposed to check for palindrome without altering the original queue.
#   After the check, the original queue is partially or completely emptied, which violates the requirement to preserve its structure.
def is_queue_palindrome(queue):
    stack = []
    temp_queue = queue.copy()
    
    for element in temp_queue:
        stack.append(element)


    for i in range(len(temp_queue)):
        if temp_queue[i] != stack.pop():
            return False

    return True
