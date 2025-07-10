class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

#  Problem 1: Palindrome Linked List
def isPalindrome(head: ListNode) -> bool:
    if not head or not head.next:
        return True
    # Step 1: Find middle
    slow = fast = head
    while fast and fast.next:
        fast = fast.next.next
        slow = slow.next
    # Step 2: Reverse second half
    prev = None
    while slow:
        nxt = slow.next
        slow.next = prev
        prev = slow
        slow = nxt
    # Step 3: Compare both halves
    left, right = head, prev
    while right:
        if left.val != right.val:
            return False
        left = left.next
        right = right.next
    return True

def build_linked_list(values):
    dummy = current = ListNode(0)
    for v in values:
        current.next = ListNode(v)
        current = current.next
    return dummy.next

def print_linked_list(head):
    vals = []
    while head:
        vals.append(str(head.val))
        head = head.next
    print(" -> ".join(vals))

if __name__ == "__main__":
    print("---- Problem 1: Palindrome Check ----")
    list = build_linked_list([1, 2, 1, 1, 2, 1])
    print("Input: 1 -> 2 -> 1 -> 1 -> 2 -> 1")
    print("Output:", isPalindrome(list))  

    list1 = build_linked_list([1, 2, 3, 4])
    print("\nInput: 1 -> 2 -> 3 -> 4")
    print("Output:", isPalindrome(list1)) 