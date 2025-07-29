from collections import deque

def generate_binary_numbers(n):
    result = []
    q = deque()
    q.append("1")

    for _ in range(n):
        front = q.popleft()
        result.append(front)
        q.append(front + "0")
        q.append(front + "1")
    
    return result

print("Binary 1 to 5:", generate_binary_numbers(5)) 
print("Binary 1 to 3:", generate_binary_numbers(3))  
