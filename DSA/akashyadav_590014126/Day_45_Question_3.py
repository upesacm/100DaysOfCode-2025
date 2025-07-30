from collections import deque

def find_max_elem(queue):
    temp=deque()
    max_val=float('-inf')

    while queue:
        elem = queue.popleft()
        max_val = max(max_val,elem)
    
    while temp:
        queue.append(temp.popleft())

    return max_val

#example
queue=deque([46,89,51])
print(find_max_elem(queue))