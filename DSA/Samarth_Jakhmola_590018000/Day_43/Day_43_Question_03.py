from collections import deque

def check_palindrome_queue(sequence):
    queue = deque(sequence)
    stack = []

    # Step 1 : Push all elements to the stac
    for ch in sequence:
        stack.append(ch)

    # Step 2 : Compare queue and stack elements
    while queue:
        front = queue.popleft()
        top = stack.pop()
        if front != top:
            return "No"
        
    return "Yes"

try:
    sequence = list(input("Enter the elements of the sequence : ").split())
    print(check_palindrome_queue(sequence))
except:
    print("Invalid input. Please try with a valid input.")
