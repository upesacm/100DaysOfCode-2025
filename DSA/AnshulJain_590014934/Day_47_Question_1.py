from collections import deque
queue = deque(map(int, input("Enter the queue elements separated by space: ").split()))
element = int(input("Enter the element to insert at rear: "))
queue.append(element)
print(list(queue))
#for example:
#input:- 1 2 3 4 5
# insert:- 6
#output:- [1, 2, 3, 4, 5, 6]