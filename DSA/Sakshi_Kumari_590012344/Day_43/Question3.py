from collections import deque

def is_palindrome_sequence(characters):
    if not isinstance(characters, deque):
        raise ValueError("Please provide the input as a deque.")

    if len(characters) == 0:
        return True

    original = deque(characters)
    reverse_stack = []

    while original:
        reverse_stack.append(original.popleft())

    original = deque(characters)

    while original:
        if original.popleft() != reverse_stack.pop():
            return False

    return True
