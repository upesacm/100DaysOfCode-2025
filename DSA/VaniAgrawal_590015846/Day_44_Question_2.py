#Implement efficient queue size calculation using appropriate methods based on the underlying queue implementation and access patterns.
from queue import Queue

elements = input("Enter the queue elements separated by space: ")
elements = list(map(int, elements.split()))
q = Queue()
for ele in elements:
    q.put(ele)

print(q.qsize())
