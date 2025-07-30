from queue import Queue

def display_queue(q):
    size = q.qsize()
    for _ in range(size):
        elem = q.get()
        print(elem, end=' ')
        q.put(elem)
    print()

q1 = Queue()
q1.put(10)
q1.put(20)
q1.put(30)
display_queue(q1)

q2 = Queue()
q2.put(5)
q2.put(15)
display_queue(q2)
