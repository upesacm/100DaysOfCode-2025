# problematic line is:
#if queue.pop(0) != stack.pop():

#answer 2
#It modifies the original queue, making the check destructive and misleading — the input is no longer usable afterward.

#correct code
def is_queue_palindrome(queue):
    stack = []
    temp_queue = queue.copy()

    for item in temp_queue:
        stack.append(item)

    for i in range(len(temp_queue)):
        if temp_queue[i] != stack.pop():
            return False

    return True
