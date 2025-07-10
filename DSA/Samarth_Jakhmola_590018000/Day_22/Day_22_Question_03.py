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

def print_linked_list(head):
    current = head
    result = []
    while current:
        result.append(str(current.val))
        current = current.next
    print(" ".join(result))

elements = list(map(int, input("Enter the elements of the linked list : ").split()))

head = create_linked_list(elements)

print_linked_list(head)
