class Node:
    def __init__(self, value):
        self.data = value
        self.next = None
def make_list(arr):
    if not arr:
        return None
    head = Node(arr[0])
    temp = head
    for num in arr[1:]:
        temp.next = Node(num)
        temp = temp.next
    return head

def print_list(head):
    while head:
        print(head.data, end=" ")
        head = head.next
    print()
def find_intersection(l1, l2):
    dummy = Node(0)
    tail = dummy
    while l1 and l2:
        if l1.data == l2.data:
            tail.next = Node(l1.data)
            tail = tail.next
            l1 = l1.next
            l2 = l2.next
        elif l1.data < l2.data:
            l1 = l1.next
        else:
            l2 = l2.next
    return dummy.next
a = list(map(int, input("Enter first sorted list: ").split()))
b = list(map(int, input("Enter second sorted list: ").split()))

list1 = make_list(a)
list2 = make_list(b)

common = find_intersection(list1, list2)

print("Intersection:")
print_list(common)
