class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def range_sum_bst_optimized(root, L, R):
    if not root:
        return 0
    
    if root.val < L:
        return range_sum_bst_optimized(root.right, L, R)
    elif root.val > R:
        return range_sum_bst_optimized(root.left, L, R)
    else:
        return (root.val + 
                range_sum_bst_optimized(root.left, L, R) + 
                range_sum_bst_optimized(root.right, L, R))

def range_sum_bst_buggy(root, L, R):
    if not root:
        return 0
    
    total = 0
    if L <= root.val <= R:
        total += root.val
    
    return total + range_sum_bst_buggy(root.left, L, R) + range_sum_bst_buggy(root.right, L, R)

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

def create_sample_tree():
    root = TreeNode(10)
    root.left = TreeNode(5)
    root.right = TreeNode(15)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(7)
    root.right.left = TreeNode(13)
    root.right.right = TreeNode(18)
    root.left.left.left = TreeNode(1)
    root.left.right.left = TreeNode(6)
    root.right.right.right = TreeNode(20)
    return root

def main():
    print("BST Range Sum Tool")
    print("=" * 20)
    
    choice = input("Use sample tree? (y/n): ").lower()
    
    if choice == 'y':
        root = create_sample_tree()
    else:
        root = create_tree()
    
    if root is None:
        print("Empty tree")
        return
    
    L = int(input("Enter range start (L): "))
    R = int(input("Enter range end (R): "))
    
    buggy_result = range_sum_bst_buggy(root, L, R)
    optimized_result = range_sum_bst_optimized(root, L, R)
    
    print(f"\nBuggy method result: {buggy_result}")
    print(f"Optimized method result: {optimized_result}")

if __name__ == "__main__":
    main()
