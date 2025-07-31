from collections import deque

def generate_binary_numbers(n):
    if not isinstance(n, int):
        raise ValueError("Input must be an integer.")
    if n <= 0:
        return []
      
    result = []
    q = deque()
    q.append("1")

    while len(result) < n:
        current = q.popleft()
        result.append(current)
        q.append(current + "0")
        q.append(current + "1")
    return result
try:
    n = 10
    binary_numbers = generate_binary_numbers(n)
    for b in binary_numbers:
        print(b)
except ValueError as e:
    print("Error:", e)
