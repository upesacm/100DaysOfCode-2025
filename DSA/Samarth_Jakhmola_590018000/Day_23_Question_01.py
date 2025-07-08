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

def kth_from_end(head, k):
    fast = slow = head

    for i in range(k):
        if not fast:
              return -1
        fast = fast.next 

    while fast:
         fast = fast.next
         slow = slow.next

    return slow.val if slow else -1

elements = list(map(int, input("Enter the elements of the linked list : ").split()))
k = int(input("Enter k : "))

head = create_linked_list(elements)

print(kth_from_end(head, k))
