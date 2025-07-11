class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

def sortedIntersect(head1, head2):
    dummy = Node(-1)
    tail = dummy

    while head1 and head2:
        if head1.val == head2.val:
            tail.next = Node(head1.val)
            tail = tail.next
            head1 = head1.next
            head2 = head2.next
        elif head1.val < head2.val:
            head1 = head1.next
        else:
            head2 = head2.next

    return dummy.next

def build_linked_list(values):
    head = Node(values[0])
    curr = head
    for v in values[1:]:
        curr.next = Node(v)
        curr = curr.next
    return head

def print_linked_list(head):
    while head:
        print(head.val, end=" -> " if head.next else "\n")
        head = head.next

list1 = build_linked_list([1, 2, 3, 4, 6])
list2 = build_linked_list([2, 4, 6, 8])
intersection = sortedIntersect(list1, list2)
print("Intersection:")
print_linked_list(intersection)