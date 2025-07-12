class Node:
    def __init__(self, data): 
        self.data = data
        self.prev = None
        self.next = None

def reverse_doubly_linked_list(head):
    if not head:
        return None

    current = head
    temp = None

    while current:
        temp = current.prev
        current.prev = current.next
        current.next = temp
        current = current.prev  

    if temp:
        head = temp.prev

    return head


def print_list(head):
    while head:
        print(head.data, end=" <-> " if head.next else "\n")
        head = head.next

def build_dll(values):
    head = None
    prev = None
    for val in values:
        node = Node(val)
        if not head:
            head = node
        else:
            prev.next = node
            node.prev = prev
        prev = node
    return head


head = build_dll([75, 122, 59, 196])
print("Before reversal:")
print_list(head)
head = reverse_doubly_linked_list(head)
print("After reversal:")
print_list(head)
