# Delete nodes following a specific pattern while maintaining proper list connections and handling edge cases.
elements = input("Enter linked list elements separated by space: ").split()
m = int(input("Enter number of nodes to skip (m): "))
n = int(input("Enter number of nodes to delete (n): "))

linked_list = [int(x) for x in elements]

def delete_n_after_m(lst, m, n):
    result = []
    i = 0
    while i < len(lst):
      
        result.extend(lst[i:i+m])
        i += m + n
    return result

final_list = delete_n_after_m(linked_list, m, n)
print(" -> ".join(map(str, final_list)))
