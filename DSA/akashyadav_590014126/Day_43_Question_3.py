from collections import deque
def is_palindrome(queue_input):
    queue=deque(queue_input)
    stack=[]

    for char in queue:
        stack.append(char)

    for char in queue:
        if char != stack.pop():
            return "No"
        
    return "Yes"