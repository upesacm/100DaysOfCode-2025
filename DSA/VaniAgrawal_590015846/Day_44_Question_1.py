#Implement queue traversal that displays all elements in FIFO order while maintaining the original queue structure and state.
from queue import Queue

elements = input("Enter the queue elements separated by space: ")
elements = list(map(int, elements.split()))

q = Queue()
for ele in elements:
    q.put(ele)

size = q.qsize()
for i in range(size):
    front = q.get()
    print(front, end=' ')
    q.put(front)
