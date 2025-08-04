from queue import Queue

def display_queue(q):
    temp=Queue()

    while not q.empty():
        elem=q.get()
        print(elem, end=' ')
        temp.put(elem)

    while not temp.empty():
        q.put(temp.get())

#example
q = Queue()
for item in [220, 330, 240]:
    q.put(item)

display_queue(q)  # Output: 10 20 30
