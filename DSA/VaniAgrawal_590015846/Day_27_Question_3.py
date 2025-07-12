# Remove every kth node from a linked list while maintaining proper connections and handling edge cases. 
def remove_kth_nodes(arr, k):
    return [arr[i] for i in range(len(arr)) if (i + 1) % k != 0]

arr = list(map(int, input("Enter singly linked list elements (space-separated): ").split()))
k = int(input("Enter k: "))
result = remove_kth_nodes(arr, k)
print(" -> ".join(map(str, result)))
