from collections import deque
def generate_binary_numbers(n):
    result=[]
    queue=deque()

    queue.append(")")

    for _ in range(n):
        current = queue.popleft()
        result.append(current)

        queue.append(current + "0")
        queue.append(current + "1")

    return result