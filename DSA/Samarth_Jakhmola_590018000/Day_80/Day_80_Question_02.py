class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Function to build tree from level-order input
def build_tree(values):
    if not values or values[0] == 'N':
        return None
    
    root = Node(int(values[0]))
    queue = [root]
    i = 1

    while queue and i < len(values):
        current = queue.pop(0)

        # Left child 
        if values[i] != 'N':
            current.left = Node(int(values[i]))
            queue.append(current.left)
        i += 1

        if i >= len(values):
            break
        
        # Right child
        if values[i] != 'N':
            current.right = Node(int(values[i]))
            queue.append(current.right)
        i += 1

    return root

# Function to find minimum value node (inorder successor)
def minValueNode(node):
    current = node
    while current.left:
        current = current.left
    return current

def deleteNode(root, key):
    if root is None:
        return root
    
    # Traverse to find the node
    if key < root.data:
        root.left = deleteNode(root.left, key)
    elif key > root.data:
        root.right = deleteNode(root.right, key)
    else:
        # Case 1 & 2 : Node with 0 or 1 child
        if root.left is None:
            return root.right
        elif root.right is None:
            return root.left
        
        # Case 3 : Node with 2 children -> replace with inorder successor
        temp = minValueNode(root.right)
        root.data = temp.data
        root.right = deleteNode(root.right, temp.data)

    return root

def inorder_traversal(root):
    if root:
        inorder_traversal(root.left)
        print(root.data, end = " ")
        inorder_traversal(root.right)

try:
    values = list(input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split())
    key = int(input("Enter the node you want to delete : "))
    inorder_traversal(deleteNode(build_tree(values), key))
except:
    print("Invalid input. Please try with a valid input.")
