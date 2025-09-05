def print_in_range(root, L, R):
    if not root:
        return
    if root.val > L:  
        print_in_range(root.left, L, R)
    if L <= root.val <= R: 
        print(root.val, end=" ")
    if root.val < R: 
        print_in_range(root.right, L, R)

root = Node(10)
root.left = Node(5)
root.right = Node(15)
root.left.left = Node(3)
root.left.right = Node(7)
root.right.right = Node(18)

print("Nodes in Range:", end=" ")
print_in_range(root, 7, 15)  
