# Delete a node at a specific position while properly handling edge cases and maintaining list connections. 
elements = input("Enter linked list elements separated by space: ").split()
x = int(input("Enter position x (1-based index) to delete: "))

linked_list = [int(x) for x in elements]

if 1 <= x <= len(linked_list):
    del linked_list[x - 1]

if linked_list:
    print(" -> ".join(map(str, linked_list)))
else:
    print("NULL")
