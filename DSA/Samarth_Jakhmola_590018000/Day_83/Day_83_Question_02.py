class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Function to insert nodes into BST
def insert(root, data):
    if root is None:
        return Node(data)
    if data < root.data:
        root.left = insert(root.left, data)
    elif data > root.data:
        root.right = insert(root.right, data)
    return root

# Serialize (Preorder Traversal)
def serialize(root):
    values = []

    def preorder(node):
        if not node:
            return 
        values.append(str(node.data))
        preorder(node.left)
        preorder(node.right)

    preorder(root)
    return ",".join(values)

# Deserialize (Rebuild BST from preorder)
def deserialize(data):
    if not data:
        return None
    
    preorder_values = list(map(int, data.split(",")))
    index = [0]  # Use list so it's mutable

    def build_bst(lower, upper):
        if index[0] == len(preorder_values):
            return None
        
        val = preorder_values[index[0]]
        if val < lower or val > upper:
            return None
        
        index[0] += 1
        node = Node(val)
        node.left = build_bst(lower, val)
        node.right = build_bst(val, upper)
        return node
    
    return build_bst(float("-inf"), float("inf"))

# Inorder traversal (for validation)
def inorder(root):
    if not root:
        return 
    inorder(root.left)
    print(root.data, end = " ")
    inorder(root.right)

try:
    values = list(map(int, input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split()))
    root = None
    for num in values:
        root = insert(root, num)

    serialized = serialize(root)

    print(f"Serialized : \n\"{serialized}\"")
    print(f"Deserialized Inorder : ")
    inorder(deserialize(serialize(root)))
except:
    print("Invalid input. Please try with a valid input.")
