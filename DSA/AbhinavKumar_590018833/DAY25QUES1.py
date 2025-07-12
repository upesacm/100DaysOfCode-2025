class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

def isPalindrome(head):
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

    prev = None
    while slow:
        temp = slow.next
        slow.next = prev
        prev = slow
        slow = temp

    first, second = head, prev
    while second:
        if first.val != second.val:
            return False
        first = first.next
        second = second.next
    return True

def build_linked_list(values):
    head = Node(values[0])
    curr = head
    for v in values[1:]:
        curr.next = Node(v)
        curr = curr.next
    return head

head = build_linked_list([1, 2, 1, 1, 2, 1])
print("Is Palindrome:", isPalindrome(head)) 

head2 = build_linked_list([1, 2, 3, 4])
print("Is Palindrome:", isPalindrome(head2))  