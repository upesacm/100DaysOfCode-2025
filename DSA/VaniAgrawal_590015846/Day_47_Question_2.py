# Add an element to the front of a queue and return the updated queue
queue = list(map(int, input("Enter elements of Queue separated by space: ").split()))
element = int(input("Enter element to insert at front: "))

queue.insert(0, element)

print("Updated Queue:", queue)
