class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def isPalindrome(head):
    if not head or not head.next:
        return True
    
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

    prev = None
    current = slow
    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node

    first_half = head
    second_half = prev
    while second_half:
        if first_half.data != second_half.data:
            return False
        first_half = first_half.next
        second_half = second_half.next

    return True

def create_linked_list(array):
        head = Node(array[0])
        current = head
        for val in array[1:]:
            current.next = Node(val)
            current = current.next
        return head

elements = list(map(int, input("Enter the elements of the linked list : ").split()))

head = create_linked_list(elements)

print("true" if isPalindrome(head) else "false")
