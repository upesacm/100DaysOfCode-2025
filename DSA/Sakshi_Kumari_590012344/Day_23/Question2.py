Your task: Remove duplicate nodes from a sorted linked list while maintaining proper node 
connections.

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
def remove_duplicates(head):
    curr = head
    while curr and curr.next:
        if curr.val == curr.next.val:
            curr.next = curr.next.next  
        else:
            curr = curr.next 
    return head
nums = list(map(int, input("Enter sorted values: ").split()))
head = create_list(nums)

head = remove_duplicates(head)

print("List after removing duplicates:")
print_list(head)



