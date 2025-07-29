from queue import Queue

def reverse_k_elements(q, k):
    if q.empty() or k <= 0:
        return q

    stack = []

    for _ in range(k):
        stack.append(q.get())

    while stack:
        q.put(stack.pop())

    size = q.qsize()
    for _ in range(size - k):
        q.put(q.get())

    return q

q = Queue()
for i in range(1, 6):
    q.put(i)

k = 3
q = reverse_k_elements(q, k)

while not q.empty():
    print(q.get(), end=' ')
