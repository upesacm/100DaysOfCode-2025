# Implement efficient duplicate detection using appropriate data structures to verify complete element uniqueness across the entire queue.
queue_input = input("Enter the elements of the queue separated by spaces: ")

queue = list(map(int, queue_input.strip().split()))

if len(queue) == len(set(queue)):
    print("True")
else:
    print("False")
