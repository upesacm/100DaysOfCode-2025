from collections import deque

def reverse_k_elements(q, k):
    stack = []
    for _ in range(k):
        stack.append(q.popleft())
    while stack:
        q.appendleft(stack.pop())
    for _ in range(len(q) - k):
        q.append(q.popleft())
    return list(q)

# Example 1
q1 = deque([1, 2, 3, 4, 5])
k1 = 3
print(reverse_k_elements(q1, k1))

# Example 2
q2 = deque([10, 20, 30])
k2 = 2
print(reverse_k_elements(q2, k2))
