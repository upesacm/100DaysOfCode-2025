from collections import deque

# 1. Reverse First K Elements of Queue
def reverse_first_k(queue, k):
    if k > len(queue) or k < 0:
        return list(queue)
    
    stack = []
    
    # Step 1: Push first k elements into stack
    for _ in range(k):
        stack.append(queue.popleft())
    
    # Step 2: Enqueue back the elements from stack
    while stack:
        queue.append(stack.pop())
    
    # Step 3: Move the remaining elements to the back to maintain order
    for _ in range(len(queue) - k):
        queue.append(queue.popleft())
    
    return list(queue)


# 2. Generate Binary Numbers from 1 to N using Queue
def generate_binary_numbers(n):
    result = []
    queue = deque()
    queue.append("1")
    
    for _ in range(n):
        current = queue.popleft()
        result.append(current)
        queue.append(current + "0")
        queue.append(current + "1")
    
    return result


# 3. Check if a Queue is Palindrome
def is_queue_palindrome(char_queue):
    stack = []
    queue = deque(char_queue)  # Make a copy to preserve original queue

    # Step 1: Push all elements to the stack
    for char in queue:
        stack.append(char)
    
    # Step 2: Compare front of queue and top of stack
    for char in queue:
        if char != stack.pop():
            return "No"
    
    return "Yes"


# === TESTING ===

# Test 1: Reverse First K Elements
q1 = deque([1, 2, 3, 4, 5])
k1 = 3
print("Reversed First K Elements:", reverse_first_k(q1, k1))  # Output: [3, 2, 1, 4, 5]

# Test 2: Generate Binary Numbers
n = 5
print("Binary Numbers from 1 to", n, ":", generate_binary_numbers(n))  # Output: ['1', '10', '11', '100', '101']

# Test 3: Check if Queue is Palindrome
char_q1 = ['r', 'a', 'c', 'e', 'c', 'a', 'r']
print("Is Palindrome:", is_queue_palindrome(char_q1))  # Output: Yes

char_q2 = ['a', 'b', 'c']
print("Is Palindrome:", is_queue_palindrome(char_q2))  # Output: No
