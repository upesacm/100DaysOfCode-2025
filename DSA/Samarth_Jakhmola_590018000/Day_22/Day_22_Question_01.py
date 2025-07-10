class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

def find_middle(head):
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow.val
    
def create_linked_list(array):
        dummy = ListNode()
        current = dummy
        for val in array:
            current.next = ListNode(val)
            current = current.next
        return dummy.next
    
elements = list(map(int, input("Enter the elements of the linked list : ").split()))
head = create_linked_list(elements)

print(find_middle(head))
