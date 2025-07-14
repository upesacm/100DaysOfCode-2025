Your task: Swap nodes at symmetric positions by manipulating pointers while maintaining 
list integrity and handling edge cases.

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def count_nodes(head):
    count = 0
    temp = head
    while temp:
        count += 1
        temp = temp.next
    return count

def swap_kth_node(head, k):
    n = count_nodes(head)
    if k > n or k <= 0 or 2 * k - 1 == n:
        return head

    prev1 = None
    node1 = head
    for _ in range(1, k):
        prev1 = node1
        node1 = node1.next

    prev2 = None
    node2 = head
    for _ in range(1, n - k + 1):
        prev2 = node2
        node2 = node2.next

    if prev1:
        prev1.next = node2
    else:
        head = node2

    if prev2:
        prev2.next = node1
    else:
        head = node1

    node1.next, node2.next = node2.next, node1.next

    return head

def print_list(head):
    temp = head
    while temp:
        print(temp.data, end=" -> " if temp.next else "\n")
        temp = temp.next
      
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)
head.next.next.next.next = Node(5)

print("Original List:")
print_list(head)

head = swap_kth_node(head, 2)

print("List After Swapping 2nd Node from Start and End:")
print_list(head)
