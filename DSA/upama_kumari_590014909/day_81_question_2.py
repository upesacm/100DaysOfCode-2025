class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def bstToSortedList(root: TreeNode) -> ListNode:
    head = prev = None

    def inorder(node):
        nonlocal head, prev
        if not node:
            return
        inorder(node.left)
        new_node = ListNode(node.val)
        if not head:
            head = new_node
        else:
            prev.next = new_node
        prev = new_node
        inorder(node.right)

    inorder(root)
    return head
