class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def bstToSortedLinkedList(root):
    dummy = ListNode(-1)
    tail = [dummy]

    def inorder(node):
        if not node:
            return
        inorder(node.left)
        tail[0].next = ListNode(node.val)
        tail[0] = tail[0].next
        inorder(node.right)

    inorder(root)
    return dummy.next
