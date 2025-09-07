def find_min(root):
    current = root
    while current and current.left:
        current = current.left
    return current.key if current else None

def find_max(root):
    current = root
    while current and current.right:
        current = current.right
    return current.key if current else None

root = Node(8)
root.left = Node(3)
root.right = Node(10)
root.left.left = Node(1)
root.left.right = Node(6)
root.right.right = Node(14)

print("Min =", find_min(root)) 
print("Max =", find_max(root)) 

root = Node(5)
print("Min =", find_min(root)) 
print("Max =", find_max(root))  
