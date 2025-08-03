def is_queue_palindrome(queue):
    stack = []
    temp_queue = queue.copy()
    queue_copy = queue.copy()  # Avoid modifying the original queue

    while temp_queue:
        element = temp_queue.pop(0)
        stack.append(element)

    while queue_copy and stack:
        if queue_copy.pop(0) != stack.pop():
            return False

    return True
