class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

def union_of_linked_lists(head1, head2):
    elements = set()

    current = head1
    while current:
        elements.add(current.val)
        current = current.next

    current = head2
    while current:
        elements.add(current.val)
        current = current.next

    sorted_elements = sorted(elements)

    dummy = ListNode()
    current = dummy
    for val in sorted_elements:
        current.next = ListNode(val)
        current = current.next

    return dummy.next

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
    print("->".join(result))

list1 = create_linked_list(list(map(int, input("Enter the elements of the 1st linked list : ").split())))
list2 = create_linked_list(list(map(int, input("Enter the elements of the 2nd linked list : ").split())))

result = union_of_linked_lists(list1, list2)
print_linked_list(result)
