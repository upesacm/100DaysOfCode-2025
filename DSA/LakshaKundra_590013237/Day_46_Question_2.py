from collections import deque

def count_even_odd(queue):
    even = odd = 0
    size = len(queue)
    for _ in range(size):
        val = queue.popleft()
        if val % 2 == 0:
            even += 1
        else:
            odd += 1
        queue.append(val)
    return even, odd

q1 = deque([1, 2, 3, 4, 5])
e, o = count_even_odd(q1)
print(f"Even: {e}, Odd: {o}")

q2 = deque([6, 8, 10])
e, o = count_even_odd(q2)
print(f"Even: {e}, Odd: {o}")
