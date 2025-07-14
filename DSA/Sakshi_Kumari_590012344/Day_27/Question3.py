Your task: Remove every kth node from a linked list while maintaining proper connections 
and handling edge cases.

class Node:
    def __init__(self, value):
        self.data = value
        self.next = None

def remove_every_kth_node(head, k):
    if head is None or k <= 0:
        return head
    if k == 1:
        return None

    current = head
    previous = None
    position = 1

    while current:
        if position % k == 0:
            previous.next = current.next
        else:
            previous = current
        current = current.next
        position += 1

    return head

def print_linked_list(head):
    current = head
    while current:
        print(current.data, end=" ")
        if current.next:
            print("->", end=" ")
        current = current.next
    print()

node1 = Node(1)
node2 = Node(2)
node3 = Node(3)
node4 = Node(4)
node5 = Node(5)
node6 = Node(6)
node7 = Node(7)
node8 = Node(8)

node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node5
node5.next = node6
node6.next = node7
node7.next = node8

head = node1
print_linked_list(head)

k = 3
head = remove_every_kth_node(head, k)

print_linked_list(head)
