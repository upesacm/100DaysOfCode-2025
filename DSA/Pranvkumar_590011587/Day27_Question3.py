class SinglyNode:
    def __init__(self, data):
        self.data = data
        self.next = None

def create_singly_linked_list(arr):
    if not arr:
        return None
    head = SinglyNode(arr[0])
    curr = head
    for val in arr[1:]:
        curr.next = SinglyNode(val)
        curr = curr.next
    return head

def print_singly_linked_list(head):
    result = []
    while head:
        result.append(str(head.data))
        head = head.next
    print(" -> ".join(result))

# Task 3: Remove every k-th node from singly linked list
def remove_every_kth_node(head, k):
    if k <= 0:
        return head
    dummy = SinglyNode(0)
    dummy.next = head
    curr = dummy
    count = 0
    while curr.next:
        count += 1
        if count % k == 0:
            curr.next = curr.next.next
        else:
            curr = curr.next
    return dummy.next


list = create_singly_linked_list([1, 2, 3, 4, 5, 6, 7, 8])
list = remove_every_kth_node(list, 2)
print_singly_linked_list(list) 

list1 = create_singly_linked_list([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
list1 = remove_every_kth_node(list1, 3)
print_singly_linked_list(list1) 
