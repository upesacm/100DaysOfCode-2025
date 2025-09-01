def insert(root, key):
    if root is None:
        return Node(key)
    
    if key < root.key:
        root.left = insert(root.left, key)
    else:
        root.right = insert(root.right, key)
    
    return root

def inorder(root):
    if root:
        inorder(root.left)
        print(root.key, end=" ")
        inorder(root.right)

root = Node(5)
root.left = Node(3)
root.right = Node(7)

root = insert(root, 4)

print("Inorder after insertion:", end=" ")
inorder(root)  
print()

root = Node(10)
root = insert(root, 20)
print("Inorder after insertion:", end=" ")
inorder(root)  
print()
