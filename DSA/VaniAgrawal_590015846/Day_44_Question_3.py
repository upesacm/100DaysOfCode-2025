#Implement reliable empty state detection that accurately identifies queue emptiness for safe operation control and error prevention.
queue_input = input("Enter the queue elements separated by space (or leave blank for empty queue): ")

if queue_input.strip() == "":
    queue = []
else:
    queue = list(map(int, queue_input.split()))

if len(queue) == 0:
    print(True)
else:
    print(False)
