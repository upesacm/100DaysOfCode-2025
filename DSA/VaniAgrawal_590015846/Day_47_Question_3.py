#Retrieve the front and rear of the queue or return an empty message
queue = list(map(int, input("Enter elements of Queue separated by space: ").split()))

if len(queue) == 0:
    print("Queue is empty")
else:
    print("Front:", queue[0])
    print("Rear:", queue[-1])
