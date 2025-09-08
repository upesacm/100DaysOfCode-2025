class Node:
    def __init__(self, value = 0, left = None, right = None):
        self.value = value
        self.left = left
        self.right = right

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

def insert_into_bst(root, key):
    # If the tree is empty, the new value becomes the root node
    if root is None:
        return Node(key)
    
    # If the key is smaller, go to the left subtree
    if key < root.value:
        root.left = insert_into_bst(root.left, key)
    else:
        # If the key is greater, go to the right subtree
        root.right = insert_into_bst(root.right, key)

    return root

def inorder(root):
    if root:
        inorder(root.left)
        print(root.value, end = " ")
        inorder(root.right)

try:
    values = list(input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split())
    key = int(input("Enter the insert to be inserted : "))
    inorder(insert_into_bst(build_tree(values), key))
except:
    print("Invalid input. Please try with a valid input.")
