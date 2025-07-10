#Reverse the direction of a linked list by changing node connections using efficient pointer manipulation.
elements = input("Enter linked list elements separated by space: ").split()
linked_list = [int(x) for x in elements]
reversed_list = linked_list[::-1]
print(" -> ".join(map(str, reversed_list)) + " -> NULL")
