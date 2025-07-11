class ListNode:
    def __init__(self, val=0, next=None): self.val, self.next = val, next
def build_list(vals):
    head = curr = ListNode(vals[0])
    for v in vals[1:]: curr.next = ListNode(v); curr = curr.next
    return head
def is_palindrome(head):
    slow = fast = head
    while fast and fast.next: slow, fast = slow.next, fast.next.next
    prev = None
    while slow: slow.next, prev, slow = prev, slow, slow.next
    while prev: 
        if head.val != prev.val: return False
        head, prev = head.next, prev.next
    return True
head = build_list(list(map(int, input("Enter The Linked List:").split())))
print(is_palindrome(head))
# Taking input from the user 
#For exampl:-
# Input: 1 2 3 2 1
# Output: True