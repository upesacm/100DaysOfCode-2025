#bug lines:
#while queue and stack:
#     if queue.pop(0) != stack.pop():
#         return False

# return len(queue) == len(stack)

#Why this causes incorrect behavior:

# queue.pop(0) mutates the original queue, removing elements from the input.
# After calling is_queue_palindrome, the input queue is no longer intact.
# The final return len(queue) == len(stack) only checks if the lengths match at the end, not whether all compared elements matched.

# Correct code:
def is_queue_palindrome(queue):
    stack = []
    temp_queue = queue.copy()

    while temp_queue:
        stack.append(temp_queue.pop(0))

    temp_queue = queue.copy()
    while temp_queue and stack:
        if temp_queue.pop(0) != stack.pop():
            return False

    return True


