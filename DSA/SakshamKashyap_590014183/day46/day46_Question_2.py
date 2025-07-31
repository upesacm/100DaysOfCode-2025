def count_even_odd(queue):
    even_count = 0
    odd_count = 0

    for item in queue:
        if item % 2 == 0:
            even_count += 1
        else:
            odd_count += 1

    return even_count, odd_count

q1 = [1, 2, 3, 4, 5]
even, odd = count_even_odd(q1)
print(f"Even: {even}, Odd: {odd}")  

q2 = [6, 8, 10]
even, odd = count_even_odd(q2)
print(f"Even: {even}, Odd: {odd}")  
