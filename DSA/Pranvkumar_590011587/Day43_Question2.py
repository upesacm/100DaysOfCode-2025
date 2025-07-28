from collections import deque
def generate_binary_numbers(n):
    result = []
    queue = deque()
    queue.append("1")
    for _ in range(n):
        front = queue.popleft()
        result.append(front)
        queue.append(front + "0")
        queue.append(front + "1")
    return result

# Examples:
print(generate_binary_numbers(5)) 
print(generate_binary_numbers(3))  