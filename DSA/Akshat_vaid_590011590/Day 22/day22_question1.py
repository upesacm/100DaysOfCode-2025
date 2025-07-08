class listnode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def build_linked_list(values):
    if not values:
        return None
    head = listnode(values[0])
    current = head 

    for val in values[1:]:
        current.next = listnode(val)
        current = current.next
    return head
def print_linked_list(head):
    current = head
    while current:
        print(current.val, end=" -> " if current.next else "\n")
        current = current.next
    print()
def findmiddle(head):
    if not head:
        return None
    slow = head
    fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    return slow

values = [2,4,6,7,5,1]
head = build_linked_list(values)
print ("Linked List:")
print_linked_list(head)

middle_node = findmiddle(head)
print("Middle Node Value:", middle_node.val if middle_node else "None")