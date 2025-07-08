# Delete the middle node of a linked list while properly handling edge cases and maintaining list connections
elements = input("Enter linked list elements separated by space: ").split()

linked_list = [int(x) for x in elements]

def delete_middle(lst):
    n = len(lst)
    if n == 0:
        return []
    if n == 1:
        return []

    mid_index = n // 2 
    del lst[mid_index]
    return lst

updated_list = delete_middle(linked_list)

if not updated_list:
    print("NULL")
else:
    print(" -> ".join(map(str, updated_list)))
