from collections import deque

def generate_binary(n):
    result = []
    q = deque()
    q.append("1")
    for _ in range(n):
        front = q.popleft()
        result.append(front)
        q.append(front + "0")
        q.append(front + "1")
    return result

# Example 1
n1 = 5
print(generate_binary(n1))

# Example 2
n2 = 3
print(generate_binary(n2))
