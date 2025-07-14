class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

def create_linked_list(array):
        dummy = ListNode()
        current = dummy
        for val in array:
            current.next = ListNode(val)
            current = current.next
        return dummy.next

def delete_middle(head):
    if not head or not head.next:
        return None
     
    slow = head
    fast = head
    prev = None

    while fast and fast.next:
        prev = slow
        slow = slow.next
        fast = fast.next.next

    prev.next = slow.next
    return head

def print_linked_list(head):
    result = []
    while head:
        result.append(str(head.val))
        head = head.next
    print("->".join(result) if result else "NULL")

elements = list(map(int, input("Enter the elements of the linked list : ").split()))

head = create_linked_list(elements)

head = delete_middle(head)

print_linked_list(head)
