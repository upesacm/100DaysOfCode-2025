class TreeNode:
    def __init__(self, value):
        self.val = value
        self.left = None
        self.right = None

class ListNode:
    def __init__(self, value):
        self.val = value
        self.next = None

def bst_to_sorted_linked_list(root):
    def inorder(node):
        nonlocal tail
        if not node:
            return
        inorder(node.left)
        tail.next = ListNode(node.val)
        tail = tail.next
        inorder(node.right)

    dummy = ListNode(0)
    tail = dummy
    inorder(root)
    return dummy.next
