# Insert an element at the end of a queue and return the updated queue.
queue = list(map(int, input("Enter elements of Queue separated by space: ").split()))
element = int(input("Enter element to insert at rear: "))

queue.append(element)

print("Updated Queue:", queue)
