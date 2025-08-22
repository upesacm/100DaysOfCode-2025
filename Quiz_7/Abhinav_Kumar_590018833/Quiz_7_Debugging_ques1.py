# def is_queue_palindrome(queue):
#     stack = []
#     temp_queue = queue.copy()

#     while temp_queue:
#         element = temp_queue.pop(0)
#         stack.append(element)

#     while queue and stack:
#         if queue.pop(0) != stack.pop():
#             return False

#     return len(queue) == len(stack)


# # Test case that reveals the bug:
# test_queue = ["r", "a", "c", "e", "c", "a", "r"]
# result = is_queue_palindrome(test_queue)
# print(f"Is palindrome: {result}")
# print(f"Original queue after check: {test_queue}")

# Tasks:

# 1. Identify the specific line(s) causing the bug 
# 2. Why this causes incorrect behavior:
def is_queue_palindrome(queue):
    stack = []
    # 1. Push all queue elements onto a stack.
    #    This loop iterates without changing the queue.
    for element in queue:
        stack.append(element)

    # 2. Compare queue elements with stack elements.
    #    This also iterates without changing the queue.
    for element in queue:
        if element != stack.pop():
            return False

    return True


test_queue = ["r", "a", "c", "e", "c", "a", "r"]
print(f"Original queue before check: {test_queue}")

result = is_queue_palindrome(test_queue)

print(f"Is palindrome: {result}")
print(f"Original queue after check: {test_queue}")

# This line causes incorrect behavior because the queue.pop(0) operation is destructive.
#  It removes elements from the original queue that was passed into the function, not a copy.
