class ListNode:
    def __init__(self, val=0, next=None): self.val, self.next = val, next
def build_list(vals):
    head = curr = ListNode(vals[0])
    for v in vals[1:]: curr.next = ListNode(v); curr = curr.next
    return head
def intersect_lists(a, b):
    dummy = curr = ListNode(0)
    while a and b:
        if a.val == b.val:
            curr.next = ListNode(a.val)
            curr, a, b = curr.next, a.next, b.next
        elif a.val < b.val:
            a = a.next
        else:
            b = b.next
    return dummy.next
def print_list(head):
    while head:
        print(head.val, end=' ')
        head = head.next
head1 = build_list(list(map(int, input("Enter Linked List One:-").split())))
head2 = build_list(list(map(int, input("Enter Linked LIst Second:-").split())))
result = intersect_lists(head1, head2)
print_list(result)
#Taking input from the user
#For example:-linked list1st = 1 2 3 4 5
#linked list2nd = 3 4 5 6 7
#Output: 3 4 5