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

def reverse_linked_list(head):
    prev = None
    current = head
    
    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node

    return prev

def print_linked_list(head):
    result = []
    while head:
        result.append(str(head.val))
        head = head.next
    print("->".join(result) + "->NULL" if result else "NULL")

elements = list(map(int, input("Enter the elements of the linked list : ").split()))

head = create_linked_list(elements)

head = reverse_linked_list(head)

print_linked_list(head)
