#Delete a node at a specific position in a doubly linked list while maintaining proper forward and backward connections.
def delete_at_position(arr, pos):
    n = len(arr)
    if pos < 1 or pos > n:
        return arr
    arr.pop(pos - 1)
    return arr

arr = list(map(int, input("Enter doubly linked list elements (space-separated): ").split()))
pos = int(input("Enter position to delete (starting from 1): "))
result = delete_at_position(arr, pos)
print(" <-> ".join(map(str, result)))
