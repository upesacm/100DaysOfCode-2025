from collections import deque

# 1. Queue Palindrome Checker Bug 

def is_queue_palindrome(queue):
    """
    Checks if the input queue is a palindrome using a stack.
    Original queue should remain unchanged after the check.
    """
    stack = []
    temp_queue = queue.copy()  # Makes a shallow copy of the original queue
    # Step 1: Push elements to the stack (reverse order)
    while temp_queue:
        element = temp_queue.pop(0)
        stack.append(element)
    # Step 2: Compare original queue and reversed stack
    while queue and stack:
        #  BUG: This line modifies the original queue
        if queue.pop(0) != stack.pop():
            return False
    #  BUG: Even if elements matched, queue and stack are now both empty, which is unnecessary
    return len(queue) == len(stack)

#  FIX: Use temp_queue for comparison to avoid modifying original
def is_queue_palindrome_fixed(queue):
    stack = []
    temp_queue = queue.copy()
    for elem in temp_queue:
        stack.append(elem)

    for elem in temp_queue:
        if elem != stack.pop():
            return False
    return True

#  Test Case for Palindrome Checker 
test_queue = ["r", "a", "c", "e", "c", "a", "r"]
result = is_queue_palindrome(test_queue)
print("Original Buggy Version:")
print(f"Is palindrome: {result}")
print(f"Original queue after check (should remain unchanged): {test_queue}")

result_fixed = is_queue_palindrome_fixed(test_queue)
print("\nFixed Version:")
print(f"Is palindrome: {result_fixed}")
print(f"Original queue after check (unchanged): {test_queue}")

# Explanation of Bug:
# 1. Line: `if queue.pop(0) != stack.pop():`
#     This line **modifies the original queue**, which is not intended.
# 2. Line: `return len(queue) == len(stack)`
#     By now both queue and stack are empty (even if it was a palindrome),
#       so comparing their lengths is redundant and misleading.