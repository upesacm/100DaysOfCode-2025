queue = []

def enqueue(queue, num):
    return queue.append(num)

def display(queue):
    print(queue)

#Fixed Input
queue = [1, 2, 3, 4, 5]
x = 6
enqueue(queue, x)
display(queue)
