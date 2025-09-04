class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def lowest_common_ancestor_bst(root, p, q):
    """
    🎯 Find LCA in BST using BST properties
    Time Complexity: O(h) where h is height of tree
    Space Complexity: O(1) - iterative approach
    
    Strategy: Use BST property to navigate efficiently
    """
    current = root
    
    while current:
        # If both nodes are in left subtree
        if p < current.val and q < current.val:
            current = current.left
        # If both nodes are in right subtree
        elif p > current.val and q > current.val:
            current = current.right
        # If nodes are on different sides or one equals current
        else:
            return current
    
    return None

def lowest_common_ancestor_recursive(root, p, q):
    """
    🚀 Recursive approach for LCA in BST
    Time Complexity: O(h)
    Space Complexity: O(h) - recursion stack
    """
    if not root:
        return None
    
    # If both nodes are smaller, LCA is in left subtree
    if p < root.val and q < root.val:
        return lowest_common_ancestor_recursive(root.left, p, q)
    
    # If both nodes are larger, LCA is in right subtree
    if p > root.val and q > root.val:
        return lowest_common_ancestor_recursive(root.right, p, q)
    
    # If nodes are on different sides or one equals root
    return root

def find_path_to_node(root, target):
    """Helper function to find path from root to target node"""
    path = []
    current = root
    
    while current:
        path.append(current.val)
        if target == current.val:
            break
        elif target < current.val:
            current = current.left
        else:
            current = current.right
    
    return path if current else []

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

def node_exists_in_bst(root, val):
    """Helper function to check if a value exists in BST"""
    current = root
    while current:
        if val == current.val:
            return True
        elif val < current.val:
            current = current.left
        else:
            current = current.right
    return False

# 🧪 Test Cases
print("=" * 60)
print("🎯 LOWEST COMMON ANCESTOR IN BST - EFFICIENT TREE NAVIGATION")
print("=" * 60)

# Test Case 1: Basic LCA
print("\n📌 Test Case 1: Basic LCA")
arr1 = [6, 2, 8, 0, 4, 7, 9, 3, 5]
root1 = build_bst_from_array(arr1)
inorder1 = inorder_display(root1)
p1, q1 = 2, 8
print(f"BST (inorder): {inorder1}")
print(f"Finding LCA of {p1} and {q1}")

# Verify nodes exist
if node_exists_in_bst(root1, p1) and node_exists_in_bst(root1, q1):
    lca1_iter = lowest_common_ancestor_bst(root1, p1, q1)
    lca1_rec = lowest_common_ancestor_recursive(root1, p1, q1)
    print(f"LCA (iterative): {lca1_iter.val if lca1_iter else None}")
    print(f"LCA (recursive): {lca1_rec.val if lca1_rec else None}")
    
    # Show paths for verification
    path_p1 = find_path_to_node(root1, p1)
    path_q1 = find_path_to_node(root1, q1)
    print(f"Path to {p1}: {' -> '.join(map(str, path_p1))}")
    print(f"Path to {q1}: {' -> '.join(map(str, path_q1))}")
else:
    print("One or both nodes don't exist in the BST")

# Test Case 2: LCA where one node is ancestor of another
print("\n📌 Test Case 2: One Node is Ancestor")
p2, q2 = 2, 4
print(f"Finding LCA of {p2} and {q2}")

if node_exists_in_bst(root1, p2) and node_exists_in_bst(root1, q2):
    lca2 = lowest_common_ancestor_bst(root1, p2, q2)
    print(f"LCA: {lca2.val if lca2 else None}")
    
    path_p2 = find_path_to_node(root1, p2)
    path_q2 = find_path_to_node(root1, q2)
    print(f"Path to {p2}: {' -> '.join(map(str, path_p2))}")
    print(f"Path to {q2}: {' -> '.join(map(str, path_q2))}")

# Test Case 3: LCA of leaf nodes
print("\n📌 Test Case 3: LCA of Leaf Nodes")
p3, q3 = 3, 5
print(f"Finding LCA of {p3} and {q3}")

if node_exists_in_bst(root1, p3) and node_exists_in_bst(root1, q3):
    lca3 = lowest_common_ancestor_bst(root1, p3, q3)
    print(f"LCA: {lca3.val if lca3 else None}")

# Test Case 4: Single node tree
print("\n📌 Test Case 4: Single Node Tree")
root4 = TreeNode(5)
print(f"Tree: {inorder_display(root4)}")
lca4 = lowest_common_ancestor_bst(root4, 5, 5)
print(f"LCA of 5 and 5: {lca4.val if lca4 else None}")

# Test Case 5: Nodes don't exist
print("\n📌 Test Case 5: Non-existent Nodes")
p5, q5 = 10, 15
print(f"Finding LCA of {p5} and {q5} (non-existent)")
if not (node_exists_in_bst(root1, p5) and node_exists_in_bst(root1, q5)):
    print("Cannot find LCA: One or both nodes don't exist in BST")

# Test Case 6: Complex BST
print("\n📌 Test Case 6: Complex BST")
arr6 = [20, 10, 30, 5, 15, 25, 35, 1, 8, 12, 18]
root6 = build_bst_from_array(arr6)
inorder6 = inorder_display(root6)
p6, q6 = 1, 18
print(f"BST (inorder): {inorder6}")
print(f"Finding LCA of {p6} and {q6}")

lca6 = lowest_common_ancestor_bst(root6, p6, q6)
print(f"LCA: {lca6.val if lca6 else None}")

# 🎯 Custom Input Section
print("\n" + "=" * 60)
print("🎯 CUSTOM INPUT TESTING")
print("=" * 60)

try:
    custom_arr = list(map(int, input("Enter BST values (space-separated): ").split()))
    p_val = int(input("Enter first node value: "))
    q_val = int(input("Enter second node value: "))
    
    custom_root = build_bst_from_array(custom_arr)
    custom_inorder = inorder_display(custom_root)
    
    print(f"\n🌳 BST (inorder): {custom_inorder}")
    print(f"🎯 Finding LCA of {p_val} and {q_val}")
    
    # Check if both nodes exist
    if node_exists_in_bst(custom_root, p_val) and node_exists_in_bst(custom_root, q_val):
        custom_lca = lowest_common_ancestor_bst(custom_root, p_val, q_val)
        print(f"💰 LCA: {custom_lca.val if custom_lca else None}")
        
        # Show paths for verification
        custom_path_p = find_path_to_node(custom_root, p_val)
        custom_path_q = find_path_to_node(custom_root, q_val)
        print(f"📊 Path to {p_val}: {' -> '.join(map(str, custom_path_p))}")
        print(f"📊 Path to {q_val}: {' -> '.join(map(str, custom_path_q))}")
    else:
        print("❌ One or both nodes don't exist in the BST")
        
except:
    print("Using default values for demonstration...")
    demo_arr = [15, 10, 20, 8, 12, 16, 25]
    demo_root = build_bst_from_array(demo_arr)
    demo_inorder = inorder_display(demo_root)
    demo_p, demo_q = 8, 12
    print(f"🌳 Demo BST (inorder): {demo_inorder}")
    print(f"🎯 Finding LCA of {demo_p} and {demo_q}")
    demo_lca = lowest_common_ancestor_bst(demo_root, demo_p, demo_q)
    print(f"💰 LCA: {demo_lca.val if demo_lca else None}")

print("\n✅ LCA finding completed using efficient BST navigation!")