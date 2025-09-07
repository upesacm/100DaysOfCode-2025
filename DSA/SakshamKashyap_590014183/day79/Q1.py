class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def delete_node(root, key):
    """
    🎯 Delete a node from BST while maintaining BST properties
    Time Complexity: O(log n) average, O(n) worst case
    Space Complexity: O(log n) average, O(n) worst case (recursion stack)
    
    Strategy: Handle 3 cases -
    1. No children: Simply remove
    2. One child: Replace with child
    3. Two children: Replace with inorder successor
    """
    if not root:
        return None
    
    # Navigate to the node to delete
    if key < root.val:
        root.left = delete_node(root.left, key)
    elif key > root.val:
        root.right = delete_node(root.right, key)
    else:
        # Found the node to delete
        
        # Case 1: No children (leaf node)
        if not root.left and not root.right:
            return None
        
        # Case 2: One child
        if not root.left:
            return root.right
        if not root.right:
            return root.left
        
        # Case 3: Two children
        # Find inorder successor (smallest in right subtree)
        successor = root.right
        while successor.left:
            successor = successor.left
        
        # Replace root's value with successor's value
        root.val = successor.val
        
        # Delete the successor
        root.right = delete_node(root.right, successor.val)
    
    return root

def inorder_traversal(root):
    """Helper function for tree visualization"""
    result = []
    def inorder(node):
        if node:
            inorder(node.left)
            result.append(node.val)
            inorder(node.right)
    inorder(root)
    return result

def build_tree_from_list(values):
    """Helper function to build BST from sorted list"""
    if not values:
        return None
    
    def build(nums):
        if not nums:
            return None
        mid = len(nums) // 2
        root = TreeNode(nums[mid])
        root.left = build(nums[:mid])
        root.right = build(nums[mid+1:])
        return root
    
    return build(sorted(values))

# 🧪 Test Cases
print("=" * 60)
print("🚀 BST NODE DELETION - MAINTAINING TREE INTEGRITY")
print("=" * 60)

# Test Case 1: Delete leaf node
print("\n📌 Test Case 1: Delete Leaf Node")
values1 = [5, 3, 6, 2, 4, 7]
root1 = build_tree_from_list(values1)
print(f"Original tree (inorder): {inorder_traversal(root1)}")
root1 = delete_node(root1, 2)
print(f"After deleting 2: {inorder_traversal(root1)}")

# Test Case 2: Delete node with one child
print("\n📌 Test Case 2: Delete Node with One Child")
values2 = [5, 3, 6, 2, 4, 7]
root2 = build_tree_from_list(values2)
print(f"Original tree (inorder): {inorder_traversal(root2)}")
root2 = delete_node(root2, 6)
print(f"After deleting 6: {inorder_traversal(root2)}")

# Test Case 3: Delete node with two children
print("\n📌 Test Case 3: Delete Node with Two Children")
values3 = [5, 3, 6, 2, 4, 7]
root3 = build_tree_from_list(values3)
print(f"Original tree (inorder): {inorder_traversal(root3)}")
root3 = delete_node(root3, 3)
print(f"After deleting 3: {inorder_traversal(root3)}")

# Test Case 4: Delete root node
print("\n📌 Test Case 4: Delete Root Node")
values4 = [5, 3, 6, 2, 4, 7]
root4 = build_tree_from_list(values4)
print(f"Original tree (inorder): {inorder_traversal(root4)}")
root4 = delete_node(root4, 5)
print(f"After deleting root 5: {inorder_traversal(root4)}")

# Test Case 5: Delete non-existent node
print("\n📌 Test Case 5: Delete Non-existent Node")
values5 = [5, 3, 6, 2, 4, 7]
root5 = build_tree_from_list(values5)
print(f"Original tree (inorder): {inorder_traversal(root5)}")
root5 = delete_node(root5, 10)
print(f"After trying to delete 10: {inorder_traversal(root5)}")

# 🎯 Custom Input Section
print("\n" + "=" * 60)
print("🎯 CUSTOM INPUT TESTING")
print("=" * 60)

try:
    custom_values = list(map(int, input("Enter tree values (space-separated): ").split()))
    delete_key = int(input("Enter key to delete: "))
    
    custom_root = build_tree_from_list(custom_values)
    print(f"\n🌳 Original BST (inorder): {inorder_traversal(custom_root)}")
    
    custom_root = delete_node(custom_root, delete_key)
    print(f"🔧 After deleting {delete_key}: {inorder_traversal(custom_root)}")
    
except:
    print("Using default values for demonstration...")
    demo_values = [8, 3, 10, 1, 6, 14, 4, 7, 13]
    demo_root = build_tree_from_list(demo_values)
    print(f"🌳 Demo BST (inorder): {inorder_traversal(demo_root)}")
    demo_root = delete_node(demo_root, 3)
    print(f"🔧 After deleting 3: {inorder_traversal(demo_root)}")

print("\n✅ BST deletion maintains tree properties efficiently!")