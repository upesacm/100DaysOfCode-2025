def is_queue_palindrome(queue):
    stack = []
    temp_queue = queue.copy()

    for element in temp_queue:
        stack.append(element)

    for element in temp_queue:
        if element != stack.pop():
            return False

    return True
