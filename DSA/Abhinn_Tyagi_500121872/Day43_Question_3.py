from collections import deque

def is_palindrome_queue(char_queue):
    stack = []
    q_copy = deque(char_queue) 
    
    for ch in q_copy:
        stack.append(ch)
    
    for ch in q_copy:
        if ch != stack.pop():
            return "No"
    return "Yes"

# Example usage
print("Is Palindrome?", is_palindrome_queue(deque(['r', 'a', 'c', 'e', 'c', 'a', 'r'])))  
print("Is Palindrome?", is_palindrome_queue(deque(['a', 'b', 'c']))) 
