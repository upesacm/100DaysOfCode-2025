class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
def create_linked_list(values):
    if not values:
        return None
    head = Node(values[0])
    curr = head
    for val in values[1:]:
        curr.next = Node(val)
        curr = curr.next
    return head
def find_kth_from_end(head, k):
    first = head
    second = head
    for _ in range(k):
        if not first:
            return -1
        first = first.next
    while first:
        first = first.next
        second = second.next
    return second.data if second else -1
values = list(map(int, input("Enter linked list elements separated by space: ").split()))
k = int(input("Enter k: "))
head = create_linked_list(values)
result = find_kth_from_end(head, k)
print(result)
