def generate_binary_numbers(n):
    if n <= 0:
        return []
    
    result = []
    queue = ["1"]  # Use list as queue
    
    for _ in range(n):
        front = queue.pop(0)   # Remove element from front (FIFO)
        result.append(front)
        queue.append(front + "0")
        queue.append(front + "1")
    
    return result

# Example usage:
n = 5
print(generate_binary_numbers(n))  # Output: ['1', '10', '11', '100', '101']
