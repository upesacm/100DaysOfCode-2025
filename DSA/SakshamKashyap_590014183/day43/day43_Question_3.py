def is_queue_palindrome(queue):
    stack = []
    n = len(queue)
    
    # Step 1: Push all elements into the stack
    for i in range(n):
        stack.append(queue[i])
    
    result = True
    # Step 2: Compare and restore queue order
    for i in range(n):
        front = queue.pop(0)   # Dequeue
        top = stack.pop()      # Pop from stack
        
        if front != top:
            result = False
        queue.append(front)    # Enqueue back to maintain original order
    
    return "Yes" if result else "No"

# Example usage:
print(is_queue_palindrome(['r', 'a', 'c', 'e', 'c', 'a', 'r']))  # Output: Yes
print(is_queue_palindrome(['a', 'b', 'c']))                      # Output: No
