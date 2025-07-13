class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

def make_list(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for v in values[1:]:
        current.next = Node(v)
        current = current.next
    return head

def print_list(head):
    while head:
        print(head.val, end=" -> " if head.next else "")
        head = head.next
    print()

def swap_kth_nodes(head, k):
    
    n = 0
    temp = head
    while temp:
        n += 1
        temp = temp.next

    if k > n:
        return head
    if 2 * k - 1 == n:
        return head  

    
    prev1 = None
    curr1 = head
    for _ in range(k - 1):
        prev1 = curr1
        curr1 = curr1.next

    prev2 = None
    curr2 = head
    for _ in range(n - k):
        prev2 = curr2
        curr2 = curr2.next

    if prev1:
        prev1.next = curr2
    if prev2:
        prev2.next = curr1

    
    curr1.next, curr2.next = curr2.next, curr1.next

    if k == 1:
        head = curr2
    if k == n:
        head = curr1

    return head

head = make_list([1, 2, 3, 4])
k = 1
print("Before swap:")
print_list(head)
head = swap_kth_nodes(head, k)
print("After swap:")
print_list(head)

