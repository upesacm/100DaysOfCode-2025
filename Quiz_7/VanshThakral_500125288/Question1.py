#Bug identified
# Line 2: if queue.pop(0) != stack.pop():
# Line 2: if queue.pop(0) != stack.pop():

#Why This Causes Incorrect Behavior
 # Original queue is destroyed because queue.pop(0) is used instead of working on a copy.

# Length check is meaningless because both structures will be empty after processing.

# The function does not preserve the queue as required, leading to unexpected side effects.

def is_queue_palindrome(queue):
    stack = []
    temp_queue = queue.copy()  

    for element in temp_queue:
        stack.append(element)

 
    for element in queue:
        if element != stack.pop():
            return False

    return True



test_queue = ["r", "a", "c", "e", "c", "a", "r"]
result = is_queue_palindrome(test_queue)
print(f"Is palindrome: {result}")
print(f"Original queue after check: {test_queue}")
