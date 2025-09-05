class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None

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

def print_list(node):
    while node:
        print(node.val, end=" ")
        node = node.next
    print()

root = Node(4)
root.left = Node(2)
root.right = Node(6)
root.left.left = Node(1)
root.left.right = Node(3)
root.right.left = Node(5)
root.right.right = Node(7)
head = bst_to_list(root)
print_list(head)

root2 = Node(2)
root2.left = Node(1)
root2.right = Node(3)
head2 = bst_to_list(root2)
print_list(head2)
