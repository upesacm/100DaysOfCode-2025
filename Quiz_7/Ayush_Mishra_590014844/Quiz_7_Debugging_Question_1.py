def is_queue_palindrome(queue):
    stack = []
    temp_queue = queue.copy()

    #step 1: push all elements of the queue into the stack
    for element in temp_queue:
        stack.append(element)

    #step 2: compare each element in queue and stack
    for i in range(len(temp_queue)):
        if temp_queue[i] != stack.pop():
            return False

    return True

#test case
test_queue = ["r", "a", "c", "e", "c", "a", "r"]
result = is_queue_palindrome(test_queue)
print(f"Is palindrome: {result}")
print(f"Original queue after check: {test_queue}")
