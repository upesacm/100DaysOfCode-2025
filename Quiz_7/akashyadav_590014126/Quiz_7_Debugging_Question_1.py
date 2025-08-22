def is_queue_palindrome(queue):
    stack = []
    temp_queue = queue.copy()

    for element in temp_queue:
        stack.append(element)

    temp_queue = queue.copy()  # Use another copy for comparison
    while temp_queue:
        if temp_queue.pop(0) != stack.pop():
            return False

    return True

#The while statement of que and stack was creating bugs
#The queue in while is passed by reference, so popping elements from it directly in the second while loop alters the original test_queue, which also violates the non-destructive behavior you'd expect in utility checks.
