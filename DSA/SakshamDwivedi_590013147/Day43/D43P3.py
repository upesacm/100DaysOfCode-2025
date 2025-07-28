queue = []

def enqueue(queue, num):
    return queue.append(num)

def deque(queue):
    if queue:
        return queue.pop(0)
    return None

def peek(queue):
    if queue:
        return queue[0]
    return None

def display(queue):
    return queue

def is_palindrome(queue):
    stack = []
    size = len(queue)

    for i in range(size):
        val = deque(queue)
        enqueue(queue, val)
        stack.append(val)
        
    for i in range(size):
        val = deque(queue)
        if val != stack.pop():
            return "No"
        enqueue(queue, val)

    return "Yes"

#Fixed Input
for i in ['r', 'a', 'c', 'e', 'c', 'a', 'r']:
    enqueue(queue, i)
print(is_palindrome(queue))
