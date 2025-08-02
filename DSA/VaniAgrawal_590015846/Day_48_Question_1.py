# Implement conditional queue traversal with selective element retention to remove all instances of the target value while preserving queue order.

queue_input = input("Enter the queue elements separated by spaces: ")
queue = list(map(int, queue_input.split()))

x = int(input("Enter the value to remove: "))

result_queue = [element for element in queue if element != x]

print("Updated queue:", result_queue)
