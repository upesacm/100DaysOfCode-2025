def front_and_rear(queue):
    if not queue:
        return "Queue is empty."
    front = queue[0]
    rear = queue[len(queue) - 1]
    return f"Front : {front}, Rear : {rear}"

try:
    queue = []
    elements = list(input("Enter the elements of the queue : ").split())
    for i in elements:
        if i.isdigit():
            queue.append(int(i))
        else:
            queue.append(i)
    print(front_and_rear(queue))
except:
    print("Invalid input. Please try with a valid input.")
