from queue import Queue

def queue_size(q):
    return q.qsize()

#example
q = Queue()
for i in [1,2,3,4,5,6,7,8,9]:
    q.put(i)

print(queue_size(q))