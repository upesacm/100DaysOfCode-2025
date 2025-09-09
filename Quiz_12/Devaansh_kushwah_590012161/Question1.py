class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def is_valid_bst(root, min_val=float('-inf'), max_val=float('inf')):
    if not root:
        return True
    
    if root.val <= min_val or root.val >= max_val:
        return False
    
    return (is_valid_bst(root.left, min_val, root.val) and 
            is_valid_bst(root.right, root.val, max_val))

def is_valid_bst_inorder(root):
    def inorder(node, values):
        if not node:
            return
        inorder(node.left, values)
        values.append(node.val)
        inorder(node.right, values)
    
    values = []
    inorder(root, values)
    
    for i in range(1, len(values)):
        if values[i] <= values[i-1]:
            return False
    return True

def create_tree():
    nodes = {}
    
    n = int(input("Enter number of nodes: "))
    if n == 0:
        return None
    
    root_val = int(input("Enter root value: "))
    root = TreeNode(root_val)
    nodes[root_val] = root
    
    for i in range(n - 1):
        child_val = int(input(f"Enter value for node {i+2}: "))
        parent_val = int(input(f"Enter parent value for {child_val}: "))
        position = input(f"Is {child_val} left or right child of {parent_val}? (l/r): ").lower()
        
        child_node = TreeNode(child_val)
        nodes[child_val] = child_node
        
        if position == 'l':
            nodes[parent_val].left = child_node
        else:
            nodes[parent_val].right = child_node
    
    return root

def main():
    print("BST Validation Tool")
    print("=" * 20)
    
    root = create_tree()
    
    if root is None:
        print("Empty tree - Valid BST: True")
        return
    
    bounds_result = is_valid_bst(root)
    inorder_result = is_valid_bst_inorder(root)
    
    print(f"\nBounds method result: {bounds_result}")
    print(f"Inorder method result: {inorder_result}")

if __name__ == "__main__":
    main()
