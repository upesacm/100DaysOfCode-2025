#: Reverse a doubly linked list by swapping both forward and backward pointers for all nodes.
def reverse_list(arr):
    return arr[::-1]

arr = list(map(int, input("Enter doubly linked list elements (space-separated): ").split()))
result = reverse_list(arr)
print(" <-> ".join(map(str, result)))
