class ListNode:
    def __init__(self, val=0, next=None): 
        self.val = val
        self.next = next

def remove_every_kth_node(head, k):
    if not head or k <= 0:
        return head
    if k == 1:
        return None  

    current = head
    prev = None
    count = 1

    while current:
        if count % k == 0:
            # Remove current node
            prev.next = current.next
            current = current.next
        else:
            prev = current
            current = current.next
        count += 1

    return head

def print_list(head):
    while head:
        print(head.val, end=" -> " if head.next else "\n")
        head = head.next

def build_sll(values):
    head = None
    tail = None
    for val in values:
        node = ListNode(val)
        if not head:
            head = node
        else:
            tail.next = node
        tail = node
    return head

head = build_sll([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
print("Before:")
print_list(head)
head = remove_every_kth_node(head, 3)
print("After removing every 3rd node:")
print_list(head)
