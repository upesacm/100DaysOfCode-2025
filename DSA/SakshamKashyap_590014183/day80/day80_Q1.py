class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def bst_to_greater_sum_tree(root):
    """
    🎯 Convert BST to Greater Sum Tree using reverse inorder traversal
    Time Complexity: O(n) - visit each node once
    Space Complexity: O(h) - recursion stack depth
    
    Strategy: Reverse inorder (right->root->left) to process nodes in descending order
    """
    def reverse_inorder(node):
        nonlocal running_sum
        if not node:
            return
        
        # Process right subtree first (larger values)
        reverse_inorder(node.right)
        
        # Update current node with running sum
        running_sum += node.val
        node.val = running_sum
        
        # Process left subtree (smaller values)
        reverse_inorder(node.left)
    
    running_sum = 0
    reverse_inorder(root)
    return root

def inorder_display(root):
    """Helper function to display tree in inorder"""
    result = []
    def inorder(node):
        if node:
            inorder(node.left)
            result.append(node.val)
            inorder(node.right)
    inorder(root)
    return result

def build_bst_from_array(arr):
    """Helper function to build BST from array"""
    if not arr:
        return None
    
    def insert(root, val):
        if not root:
            return TreeNode(val)
        if val < root.val:
            root.left = insert(root.left, val)
        else:
            root.right = insert(root.right, val)
        return root
    
    root = None
    for val in arr:
        root = insert(root, val)
    return root

# 🧪 Test Cases
print("=" * 60)
print("🎯 BST TO GREATER SUM TREE - CUMULATIVE TRANSFORMATION")
print("=" * 60)

# Test Case 1: Basic BST
print("\n📌 Test Case 1: Basic BST")
arr1 = [4, 1, 6, 0, 2, 5, 7, 3, 8]
root1 = build_bst_from_array(arr1)
original1 = inorder_display(root1)
print(f"Original BST (inorder): {original1}")
bst_to_greater_sum_tree(root1)
transformed1 = inorder_display(root1)
print(f"Greater Sum Tree: {transformed1}")

# Test Case 2: Single node
print("\n📌 Test Case 2: Single Node BST")
root2 = TreeNode(5)
print(f"Original BST: {inorder_display(root2)}")
bst_to_greater_sum_tree(root2)
print(f"Greater Sum Tree: {inorder_display(root2)}")

# Test Case 3: Left-skewed BST
print("\n📌 Test Case 3: Left-skewed BST")
arr3 = [5, 4, 3, 2, 1]
root3 = build_bst_from_array(arr3)
original3 = inorder_display(root3)
print(f"Original BST (inorder): {original3}")
bst_to_greater_sum_tree(root3)
transformed3 = inorder_display(root3)
print(f"Greater Sum Tree: {transformed3}")

# 🎯 Custom Input Section
print("\n" + "=" * 60)
print("🎯 CUSTOM INPUT TESTING")
print("=" * 60)

try:
    custom_arr = list(map(int, input("Enter BST values (space-separated): ").split()))
    custom_root = build_bst_from_array(custom_arr)
    custom_original = inorder_display(custom_root)
    print(f"\n🌳 Original BST (inorder): {custom_original}")
    
    bst_to_greater_sum_tree(custom_root)
    custom_transformed = inorder_display(custom_root)
    print(f"🔧 Greater Sum Tree: {custom_transformed}")
    
except:
    print("Using default values for demonstration...")
    demo_arr = [6, 3, 8, 2, 5, 7, 9]
    demo_root = build_bst_from_array(demo_arr)
    demo_original = inorder_display(demo_root)
    print(f"🌳 Demo BST (inorder): {demo_original}")
    bst_to_greater_sum_tree(demo_root)
    demo_transformed = inorder_display(demo_root)
    print(f"🔧 Greater Sum Tree: {demo_transformed}")

print("\n✅ BST to Greater Sum Tree transformation completed efficiently!")

