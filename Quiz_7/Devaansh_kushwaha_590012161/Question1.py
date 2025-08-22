from collections import deque

def is_queue_palindrome_fixed(queue_list):
    temp_list_for_stack = queue_list[:]

    stack = []
    
    while temp_list_for_stack:
        element = temp_list_for_stack.pop(0)
        stack.append(element)
    
    for i in range(len(queue_list)):
        if queue_list[i] != stack.pop():
            return False
            
    return True

test_queue = ["r", "a", "c", "e", "c", "a", "r"]
result = is_queue_palindrome_fixed(test_queue)
print(f"Is palindrome: {result}")
print(f"Original queue after check: {test_queue}")

test_queue_2 = ["a", "b", "c"]
result_2 = is_queue_palindrome_fixed(test_queue_2)
print(f"Is palindrome: {result_2}")
print(f"Original queue after check: {test_queue_2}")
