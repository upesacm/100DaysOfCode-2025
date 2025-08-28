def isBalanced(root):
    def check(node):
        if node is None:
            return 0
        left = check(node.left)
        if left == -1:
            return -1
        right = check(node.right)
        if right == -1:
            return -1
        if abs(left - right) > 1:
            return -1
        return max(left, right) + 1
    
    return check(root) != -1

root = Node(1)
root.left = Node(2)
root.left.left = Node(3)

print("Balanced?", "Yes" if isBalanced(root) else "No")

root2 = Node(1)
root2.left = Node(2)
root2.right = Node(3)

print("Balanced?", "Yes" if isBalanced(root2) else "No")
