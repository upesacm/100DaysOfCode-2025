from collections import deque

def count_even_odd(queue):
    even_count = 0
    odd_count = 0
    temp_queue = deque()

    while queue:
        val = queue.popleft()
        if val % 2 == 0:
            even_count += 1
        else:
            odd_count += 1
        temp_queue.append(val)

    while temp_queue:
        queue.append(temp_queue.popleft())

    return even_count, odd_count

#example
q = deque([43 , 44 , 45 , 46 , 47])
even, odd = count_even_odd(q)
print(f"Even: {even}, Odd: {odd}")