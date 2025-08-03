from collections import deque

def compare_queues(q1, q2):
    if len(q1) != len(q2):
        return "No"
    temp1, temp2 = deque(), deque()
    identical = True
    while q1:
        a, b = q1.popleft(), q2.popleft()
        temp1.append(a)
        temp2.append(b)
        if a != b:
            identical = False
    # Restore original queues
    while temp1:
        q1.append(temp1.popleft())
        q2.append(temp2.popleft())
    return "Yes" if identical else "No"

# Example
q1 = deque([1, 2, 3])
q2 = deque([1, 2, 3])
print(compare_queues(q1, q2))  