Your task: Find the kth node from the end of a linked list using efficient single-pass traversal 
techniques.

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

def get_count(start):
    count = 0
    while start:
        count += 1
        start = start.next
    return count

def kth_from_end(start, k):
    total = get_count(start)
    if k > total or k <= 0:
        return -1
    move = total - k
    curr = start
    for _ in range(move):
        curr = curr.next
    return curr.val
nums = list(map(int, input("Enter values: ").split()))
k = int(input("Enter k: "))

head = create_list(nums)
ans = kth_from_end(head, k)

if ans == -1:
    print("-1")
else:
    print("Kth node from end:", ans)
