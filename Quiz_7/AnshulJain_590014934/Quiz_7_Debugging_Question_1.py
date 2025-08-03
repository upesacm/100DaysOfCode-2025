def is_queue_palindrome(queue):
    stack = []
    temp_queue = queue.copy()
    while temp_queue:
        element = temp_queue.pop(0)
        stack.append(element)
    while queue and stack:
        if queue.pop(0) != stack.pop():
            return False
    return len(queue) == len(stack)
# Test case that reveals the bug:
test_queue = ["r", "a", "c", "e", "c", "a", "r"]
result = is_queue_palindrome(test_queue)
print(f"Is palindrome: {result}")
print(f"Original queue after check: {test_queue}")
#Answer of the given task Question 
# 1. Line(s) causing the bug: 
#     `while queue and stack:`
#     `if queue.pop(0) != stack.pop():`
# 2. Why this causes incorrect behavior:
#     These lines mutate the original `queue` by popping elements, which destroys its contents.
#     As a result, `test_queue` is modified after the function call.
#     This side effect breaks the expectation that input data remains unchanged during a check.
