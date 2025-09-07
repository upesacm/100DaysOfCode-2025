from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def tree_height_nodes(root):
    """
    Height measured as number of nodes along longest path.
    Empty tree -> 0, single node -> 1
    """
    if root is None:
        return 0
    left_h = tree_height_nodes(root.left)
    right_h = tree_height_nodes(root.right)
    return 1 + max(left_h, right_h)   # <-- FIXED: add 1 for current node

def tree_height_edges(root):
    """
    Height measured as number of edges along longest path.
    Empty tree -> -1, single node -> 0
    """
    if root is None:
        return -1
    return 1 + max(tree_height_edges(root.left), tree_height_edges(root.right))

def build_tree_level_order(tokens):
    """
    Build binary tree from level-order tokens (strings).
    Use 'N', 'n', 'null', 'None' or '#' for missing nodes.
    Example: "1 2 3 N 4" -> root=1, left=2, right=3, 2.right=4
    """
    if not tokens:
        return None
    it = iter(tokens)
    first = next(it)
    if first.lower() in ('n','null','none','#'):
        return None
    try:
        root = TreeNode(int(first))
    except ValueError:
        root = TreeNode(first)  # if not integer, keep as string
    q = deque([root])

    while q:
        node = q.popleft()
        try:
            left_val = next(it)
        except StopIteration:
            break
        if left_val.lower() not in ('n','null','none','#'):
            try:
                node.left = TreeNode(int(left_val))
            except ValueError:
                node.left = TreeNode(left_val)
            q.append(node.left)

        try:
            right_val = next(it)
        except StopIteration:
            break
        if right_val.lower() not in ('n','null','none','#'):
            try:
                node.right = TreeNode(int(right_val))
            except ValueError:
                node.right = TreeNode(right_val)
            q.append(node.right)
    return root

if __name__ == "__main__":
    s = input("Enter level-order node values (space-separated). Use N/null for missing. [Press Enter for sample tests] \n> ").strip()
    if s == "":
        # Sample tests
        print("\nRunning sample tests...")

        # Test 1: skewed left: 1 -> 2 -> 3
        tokens = "1 2 N 3".split()
        root = build_tree_level_order(tokens)
        print("Tree (1-left-2-left-3). Expected height (nodes) = 3. Computed:", tree_height_nodes(root))
        print("Same tree height (edges) = ", tree_height_edges(root))

        # Test 2: single node
        root2 = build_tree_level_order(["1"])
        print("Single node. Expected height (nodes) = 1. Computed:", tree_height_nodes(root2))
        print("Single node height (edges) = ", tree_height_edges(root2))
    else:
        tokens = s.split()
        root = build_tree_level_order(tokens)
        print("Computed height (nodes):", tree_height_nodes(root))
        print("Computed height (edges):", tree_height_edges(root))
