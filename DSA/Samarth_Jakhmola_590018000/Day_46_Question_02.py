from collections import deque

def even_odd(queue):
    even = odd = 0

    for _ in range(len(queue)):
        current = queue.popleft()
        if current % 2 == 0:
            even += 1
        else:
            odd += 1
        queue.append(current)

    return even, odd

try:
    queue = deque(list(map(int, input("Enter the elements of the queue : ").split())))
    even, odd = even_odd(queue)
    print(f"Even: {even}, Odd: {odd}")
except:
    print("Invalid input. Please try with a valid input.")
