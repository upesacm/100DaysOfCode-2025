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
    result = []
    while head:
        result.append(str(head.val))
        head = head.next
    print("->".join(result) if result else "NULL")

def delete_at_position(head, x):
    if x <= 0:
         print("Invalid position.")
         return head

    dummy = ListNode(0)
    dummy.next = head
    prev = dummy
    current = head

    for i in range(1, x):
         if current is None:
              print("Position out of bounds.")
              return head
         prev = current
         current = current.next

    if current:
         prev.next = current.next
    else:
         print("Position out of bounds.")
    return dummy.next       

elements = list(map(int, input("Enter the elements of the linked list : ").split()))
x = int(input("Enter position x to be deleted : "))

head = create_linked_list(elements)

head = delete_at_position(head, x)

print_linked_list(head)
