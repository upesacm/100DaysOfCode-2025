'''1. the bug is line 
return len(queue) == len(stack)
2.Why This Causes Incorrect Behavior: The queue is being emptied as elements are removed during the check.
By the time it checks len(queue), the queue is already empty, while the stack still has elements. This means
the comparison will always be False for palindromes. Instead, it should check if both the queue and stack are 
empty at the end to confirm a palindrome. A better return.

correct code:'''
def is_queue_palindrome(queue):
    stack = []
    temp_queue = queue.copy()
    while temp_queue:
        element = temp_queue.pop(0)
        stack.append(element)
    while queue and stack:
        if queue.pop(0) != stack.pop():
            return False
    return not queue and not stack
test_queue = ["r", "a", "c", "e", "c", "a", "r"]
result = is_queue_palindrome(test_queue)
print(f"Is palindrome: {result}")
print(f"Original queue after check: {test_queue}")
