class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None

def bst_to_sorted_list(root):
    def inorder(node):
        nonlocal prev, head
        if not node:
            return
        inorder(node.left)

    
        new_node = ListNode(node.val)
        if prev:
            prev.next = new_node
        else:
            head = new_node
        prev = new_node

        inorder(node.right)

    prev, head = None, None
    inorder(root)
    return head

root = Node(4)
root.left = Node(2)
root.right = Node(6)
root.left.left = Node(1)
root.left.right = Node(3)
root.right.left = Node(5)
root.right.right = Node(7)

head = bst_to_sorted_list(root)
print("Sorted Linked List:", end=" ")
while head:
    print(head.val, end=" → " if head.next else "\n")
    head = head.next
