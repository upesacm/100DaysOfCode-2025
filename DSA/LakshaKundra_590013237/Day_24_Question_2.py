class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def delete_n_after_m(head, m, n):
    current = head
    while current:
        for _ in range(1, m):
            if not current:
                return head
            current = current.next
        temp = current
        for _ in range(n):
            if temp and temp.next:
                temp = temp.next
            else:
                break
        if temp:
            current.next = temp.next
            current = temp.next
        else:
            break
    return head

def create_linked_list(arr):
    if not arr:
        return None
    head = Node(arr[0])
    temp = head
    for val in arr[1:]:
        temp.next = Node(val)
        temp = temp.next
    return head

def print_linked_list(head):
    res = []
    while head:
        res.append(str(head.data))
        head = head.next
    print("->".join(res))

head1 = create_linked_list([9,1,3,5,9,4,10,1])
head1 = delete_n_after_m(head1, 2, 1)
print_linked_list(head1)  # Output: 9->1->5->9->10->1

head2 = create_linked_list([1,2,3,4,5,6])
head2 = delete_n_after_m(head2, 6, 1)
print_linked_list(head2)  # Output: 1->2->3->4->5->6
