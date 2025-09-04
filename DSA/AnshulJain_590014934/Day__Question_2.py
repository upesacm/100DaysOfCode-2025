class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None

def insert(root, val):
    if not root:
        return TreeNode(val)
    if val < root.val:
        root.left = insert(root.left, val)
    else:
        root.right = insert(root.right, val)
    return root

def bst_to_list(root):
    def inorder(node):
        nonlocal head, tail
        if not node:
            return
        inorder(node.left)
        new_node = ListNode(node.val)
        if not head:
            head = new_node
            tail = new_node
        else:
            tail.next = new_node
            tail = new_node
        inorder(node.right)

    head, tail = None, None
    inorder(root)
    return head

n = int(input("Enter number of nodes: "))
values = list(map(int, input("Enter node values: ").split()))

root = None
for v in values:
    root = insert(root, v)

linked_list = bst_to_list(root)

result = []
while linked_list:
    result.append(str(linked_list.val))
    linked_list = linked_list.next

print(" → ".join(result))
