from queue import Queue

def is_queue_empty(q):
    return q.empty()

#example
q=Queue()
for i in []:
    q.put(i)

print(is_queue_empty(q))