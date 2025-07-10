class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

def count_key(head, key):

    count = 0
    current = head
    while current:
        if current.val == key:
            count += 1
        current = current.next
    return count

def create_linked_list(array):
        dummy = ListNode()
        current = dummy
        for val in array:
            current.next = ListNode(val)
            current = current.next
        return dummy.next
    
elements = list(map(int, input("Enter the elements of the linked list : ").split()))
key = int(input("Enter the key to be counted : "))

head = create_linked_list(elements)

print(count_key(head, key))
