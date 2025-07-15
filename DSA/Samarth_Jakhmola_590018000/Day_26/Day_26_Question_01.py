class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

def swap_kth_nodes(head, k):
    n = 0
    current = head
    while current:
        n += 1
        current = current.next

    if k > n:
        return False
    
    if 2*k - 1 == n:
        return True
    
    prev_x, x = None, head
    for i in range(k-1):
        prev_x = x
        x = x.next

    prev_y, y = None, head
    for i in range(n-k):
        prev_y = y
        y = y.next

    if prev_x:
        prev_x.next = y
    if prev_y:
        prev_y.next = x

    x.next, y.next = y.next, x.next

    if k == 1:
        head = y
    if k == n:
        head = x

    return True

def create_linked_list(array):
        dummy = ListNode()
        current = dummy
        for val in array:
            current.next = ListNode(val)
            current = current.next
        return dummy.next

elements = list(map(int, input("Enter the elements of the linked list : ").split()))
k = int(input("Enter the value of k : "))

head = create_linked_list(elements)

print("true" if swap_kth_nodes(head, k) else "false")
