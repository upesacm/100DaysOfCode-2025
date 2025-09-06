class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def is_valid_bst(root):
    """
    🎯 Validate BST using range validation approach
    Time Complexity: O(n) - visit each node once
    Space Complexity: O(h) - recursion stack depth
    
    Strategy: Use min/max bounds to validate each node's position
    """
    def validate(node, min_val, max_val):
        if not node:
            return True
        
        # Check if current node violates BST property
        if node.val <= min_val or node.val >= max_val:
            return False
        
        # Recursively validate left and right subtrees with updated bounds
        return (validate(node.left, min_val, node.val) and
                validate(node.right, node.val, max_val))
    
    return validate(root, float('-inf'), float('inf'))

def is_valid_bst_inorder(root):
    """
    🚀 Alternative approach using inorder traversal
    Time Complexity: O(n)
    Space Complexity: O(n) for storing inorder sequence
    """
    def inorder(node):
        if not node:
            return []
        return inorder(node.left) + [node.val] + inorder(node.right)
    
    inorder_seq = inorder(root)
    
    # Check if inorder sequence is strictly increasing
    for i in range(1, len(inorder_seq)):
        if inorder_seq[i] <= inorder_seq[i-1]:
            return False
    return True

def build_tree_from_preorder(preorder):
    """Helper function to build tree from preorder traversal"""
    if not preorder:
        return None
    
    def build(min_val, max_val):
        nonlocal idx
        if idx >= len(preorder):
            return None
        
        val = preorder[idx]
        if val < min_val or val > max_val:
            return None
        
        idx += 1
        root = TreeNode(val)
        root.left = build(min_val, val)
        root.right = build(val, max_val)
        return root
    
    idx = 0
    return build(float('-inf'), float('inf'))

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

# 🧪 Test Cases
print("=" * 60)
print("🎯 BST VALIDATION - STRUCTURAL INTEGRITY VERIFICATION")
print("=" * 60)

# Test Case 1: Valid BST
print("\n📌 Test Case 1: Valid BST")
# Build: 2 / \ 1 3
root1 = TreeNode(2, TreeNode(1), TreeNode(3))
inorder1 = inorder_display(root1)
print(f"Tree (inorder): {inorder1}")
result1_range = is_valid_bst(root1)
result1_inorder = is_valid_bst_inorder(root1)
print(f"Range validation: {'Valid BST' if result1_range else 'Invalid BST'}")
print(f"Inorder validation: {'Valid BST' if result1_inorder else 'Invalid BST'}")

# Test Case 2: Invalid BST
print("\n📌 Test Case 2: Invalid BST")
# Build: 5 / \ 1 4 / \ 3 6 (violates BST property)
root2 = TreeNode(5, TreeNode(1), TreeNode(4, TreeNode(3), TreeNode(6)))
inorder2 = inorder_display(root2)
print(f"Tree (inorder): {inorder2}")
result2_range = is_valid_bst(root2)
result2_inorder = is_valid_bst_inorder(root2)
print(f"Range validation: {'Valid BST' if result2_range else 'Invalid BST'}")
print(f"Inorder validation: {'Valid BST' if result2_inorder else 'Invalid BST'}")

# Test Case 3: Single node
print("\n📌 Test Case 3: Single Node")
root3 = TreeNode(1)
print(f"Tree (inorder): {inorder_display(root3)}")
result3 = is_valid_bst(root3)
print(f"Validation result: {'Valid BST' if result3 else 'Invalid BST'}")

# Test Case 4: Empty tree
print("\n📌 Test Case 4: Empty Tree")
root4 = None
result4 = is_valid_bst(root4)
print(f"Empty tree validation: {'Valid BST' if result4 else 'Invalid BST'}")

# Test Case 5: Complex valid BST
print("\n📌 Test Case 5: Complex Valid BST")
# Build from preorder: [8, 3, 1, 6, 4, 7, 10, 14, 13]
preorder5 = [8, 3, 1, 6, 4, 7, 10, 14, 13]
root5 = build_tree_from_preorder(preorder5)
inorder5 = inorder_display(root5)
print(f"Tree (inorder): {inorder5}")
result5 = is_valid_bst(root5)
print(f"Validation result: {'Valid BST' if result5 else 'Invalid BST'}")

# Test Case 6: Edge case with duplicates (should be invalid)
print("\n📌 Test Case 6: Tree with Duplicates")
# Build: 2 / \ 2 3 (duplicates make it invalid)
root6 = TreeNode(2, TreeNode(2), TreeNode(3))
inorder6 = inorder_display(root6)
print(f"Tree (inorder): {inorder6}")
result6 = is_valid_bst(root6)
print(f"Validation result: {'Valid BST' if result6 else 'Invalid BST'}")

# 🎯 Custom Input Section
print("\n" + "=" * 60)
print("🎯 CUSTOM INPUT TESTING")
print("=" * 60)

try:
    print("Enter tree structure manually:")
    print("Format: node_value left_child right_child (use 'None' for empty nodes)")
    print("Example: 2 1 3 (creates tree with root 2, left child 1, right child 3)")
    
    # Simple custom input for demonstration
    root_val = int(input("Enter root value: "))
    custom_root = TreeNode(root_val)
    
    left_input = input("Enter left child value (or 'None'): ")
    if left_input.lower() != 'none':
        custom_root.left = TreeNode(int(left_input))
    
    right_input = input("Enter right child value (or 'None'): ")
    if right_input.lower() != 'none':
        custom_root.right = TreeNode(int(right_input))
    
    custom_inorder = inorder_display(custom_root)
    print(f"\n🌳 Custom tree (inorder): {custom_inorder}")
    
    custom_result = is_valid_bst(custom_root)
    print(f"🔧 Validation result: {'Valid BST' if custom_result else 'Invalid BST'}")
    
except:
    print("Using default values for demonstration...")
    demo_root = TreeNode(5, TreeNode(3, TreeNode(2), TreeNode(4)), TreeNode(8, TreeNode(7), TreeNode(9)))
    demo_inorder = inorder_display(demo_root)
    print(f"🌳 Demo tree (inorder): {demo_inorder}")
    demo_result = is_valid_bst(demo_root)
    print(f"🔧 Validation result: {'Valid BST' if demo_result else 'Invalid BST'}")

print("\n✅ BST validation completed with comprehensive checking!")