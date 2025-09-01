class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def search(root, key):
    if root is None:
        return False
    
    if root.key == key:
        return True
    elif key < root.key:
        return search(root.left, key)
    else:
        return search(root.right, key)

root = Node(5)
root.left = Node(3)
root.right = Node(7)
root.left.left = Node(2)
root.left.right = Node(4)
root.right.left = Node(6)
root.right.right = Node(8)

print("Yes" if search(root, 4) else "No")   
print("Yes" if search(root, 10) else "No")  
