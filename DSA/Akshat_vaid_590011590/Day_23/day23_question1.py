class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def build_linked_list(values):
    if not values:
        return None

    head = ListNode(values[0])
    current = head

    for val in values[1:]:
        current.next = ListNode(val)
        current = current.next

    return head

def find_kth_from_end(head, k):
    first = head
    second = head

   
    for i in range(k):
        if not first:
            return -1  
        first = first.next

    while first:
        first = first.next
        second = second.next

    return second.val if second else -1

values = [1, 2, 3, 4, 5, 6, 7, 8, 9]
k = 2

head = build_linked_list(values)
result = find_kth_from_end(head, k)
print("Kth Node from End:", result)
