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

def remove_duplicates(head):
    current = head
    while current and current.next:
         if current.val == current.next.val:
              current.next = current.next.next
         else:
              current = current.next
    return head

def print_linked_list(head):
    result = []
    while head:
        result.append(str(head.val))
        head = head.next
    print("->".join(result))

elements = list(map(int, input("Enter the elements of the linked list : ").split()))

head = create_linked_list(elements)

head = remove_duplicates(head)

print_linked_list(head)
