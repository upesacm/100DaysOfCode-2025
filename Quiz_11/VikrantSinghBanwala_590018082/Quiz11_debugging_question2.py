#1.incorrect line :
#root.val = left_sum + right_sum

#2.why?
#This line ignThis line ignores the fact that left_sum and right_sum already include the values of the child nodes 
#and their subtrees.
#Because of that, the logic becomes confusing and doesn’t clearly guarantee the expected leaf = 0 behavior
# in all cases.ores the fact that left_sum and right_sum already include the values of the child nodes and their
# subtrees.

#3. correct code:
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def convert_to_sum_tree(root):
    if root is None:
        return 0
    old_val = root.val
    left_sum = convert_to_sum_tree(root.left)
    right_sum = convert_to_sum_tree(root.right)
    root.val = left_sum + right_sum
    return root.val + old_val


root = TreeNode(1,
                TreeNode(2, TreeNode(4), TreeNode(5)),
                TreeNode(3))

def print_inorder(root):
    if root:
        print_inorder(root.left)
        print(root.val, end=" ")
        print_inorder(root.right)

print("Original tree (inorder):")
print_inorder(root)
print()

convert_to_sum_tree(root)

print("After conversion (inorder):")
print_inorder(root)
print()
