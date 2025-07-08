Your task: Delete the middle node of a linked list while properly handling edge cases and 
maintaining list connections.

class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

def create_list(nums):
    if not nums:
        return None
    head = Node(nums[0])
    curr = head
    for num in nums[1:]:
        curr.next = Node(num)
        curr = curr.next
    return head

def print_list(head):
    while head:
        print(head.val, end=" ")
        head = head.next
    print()

def delete_middle(head):
    if head is None or head.next is None:
        return None

    slow = head
    fast = head
    prev = None

    while fast and fast.next:
        fast = fast.next.next
        prev = slow
        slow = slow.next

    prev.next = slow.next
    return head
nums = list(map(int, input("Enter linked list values: ").split()))
head = create_list(nums)

head = delete_middle(head)

print("List after deleting middle node:")
print_list(head)
