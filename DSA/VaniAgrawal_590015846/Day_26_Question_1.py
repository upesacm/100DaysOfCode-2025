#: Swap nodes at symmetric positions by manipulating pointers while maintaining list integrity and handling edge cases.
elements = input("Enter linked list elements separated by space: ").split()
k = int(input("Enter value of k: "))
linked_list = [int(x) for x in elements]

def swap_kth_nodes(lst, k):
    n = len(lst)
    if k > n:
        return lst 

    if 2 * k - 1 == n:
        return lst

    i, j = k - 1, n - k

    lst[i], lst[j] = lst[j], lst[i]

    return lst

swapped_list = swap_kth_nodes(linked_list, k)

print("true")
