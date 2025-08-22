# 1. Queue Palindrome Checker Bug

# The following implementation is intended to check if a queue forms a palindrome using queue and stack operations. However, it contains bugs. Identify the error and explain why it causes incorrect behavior:


def is_queue_palindrome(queue):
    stack = []
    temp_queue = queue.copy()

    # Push all elements into stack
    for element in temp_queue:
        stack.append(element)

    # Compare temp_queue and stack
    for element in temp_queue:
        if element != stack.pop():
            return False

    return True


# Test case that reveals the bug:
test_queue = ["r", "a", "c", "e", "c", "a", "r"]
result = is_queue_palindrome(test_queue)
print(f"Is palindrome: {result}")
print(f"Original queue after check: {test_queue}")

# Tasks:
# 1. Identify the specific line(s) causing the bug 
# line 10
# 2. Why this causes incorrect behavior:
#chnages og queue