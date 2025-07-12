# Create union of two linked lists with distinct elements in sorted order using efficient merging and deduplication.
L1 = list(map(int, input("Enter elements of Linked List L1 (space-separated): ").split()))
L2 = list(map(int, input("Enter elements of Linked List L2 (space-separated): ").split()))

sorted_union = sorted(union_set)

print(" -> ".join(map(str, sorted_union)))
