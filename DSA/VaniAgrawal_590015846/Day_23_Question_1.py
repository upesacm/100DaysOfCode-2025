# Find the kth node from the end of a linked list using efficient single-pass traversal techniques. 

elements = input("Enter linked list elements separated by space: ").split()
k = int(input("Enter value of k: "))


linked_list = [int(x) for x in elements]


def find_kth_from_end(lst, k):
    n = len(lst)
    if k > n:
        return -1
    return lst[-k]


print(find_kth_from_end(linked_list, k))
