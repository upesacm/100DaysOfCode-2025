#1. Bug :-
#  while queue and stack:
  #  if queue.pop(0) != stack.pop():
   #     return False

#2. test_queue is passed into the function as queue.

#Inside the function, the line queue.pop(0) modifies the original list in-place.

#So, after the function runs, test_queue is no longer the same as before — it is now empty or partially consumed.


#3. Corrected code:-
def is_queue_palindrome(queue):
    stack = []
    temp_queue = queue.copy()

    while temp_queue:
        element = temp_queue.pop(0)
        stack.append(element)

    temp_queue = queue.copy()
    while temp_queue and stack:
        if temp_queue.pop(0) != stack.pop():
            return False

    return True


# Test case that reveals the bug:
test_queue = ["r", "a", "c", "e", "c", "a", "r"]
result = is_queue_palindrome(test_queue)
print(f"Is palindrome: {result}")
print(f"Original queue after check: {test_queue}")
