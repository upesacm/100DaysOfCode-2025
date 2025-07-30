from collections import deque

def sum_of_elements(queue):
    temp = deque()
    total=0

    while queue:
        elem = queue.popleft()
        total += elem
        temp.append(elem)

    while temp:
        queue.append(temp.popleft())

    return total

#example
q=deque([34,56,78])
print(sum_of_elements(q))