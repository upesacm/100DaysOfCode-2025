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

def inorderTraversal(root):
    if root is None:
        return
    inorderTraversal(root.left)
    print(root.data, end = " ")
    inorderTraversal(root.right)


values = list(input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split())
inorderTraversal(build_tree(values))
