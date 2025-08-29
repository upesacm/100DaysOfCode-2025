def printPaths(root, path=[]):
    if root is None:
        return
    
    path.append(root.data)

    if root.left is None and root.right is None:
        print("->".join(map(str, path)))
    else:
        printPaths(root.left, path)
        printPaths(root.right, path)
    
    path.pop() 

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.right = Node(5)

print("All Root-to-Leaf Paths:")
printPaths(root)
