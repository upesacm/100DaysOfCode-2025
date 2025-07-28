from collections import deque

def reverse_k_elements(q, k):
    if k > len(q) or k < 0:
        return q  

    stack = []

    for _ in range(k):
        stack.append(q.popleft())

    while stack:
        q.append(stack.pop())
 
    for _ in range(len(q) - k):
        q.append(q.popleft())
    
    return list(q)

q1 = deque([1, 2, 3, 4, 5])
print("Output:", reverse_k_elements(q1, 3)) 

q2 = deque([10, 20, 30])
print("Output:", reverse_k_elements(q2, 2)) 
