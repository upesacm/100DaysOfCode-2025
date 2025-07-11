class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def intersect_sorted_lists(head1, head2):
    dummy = Node(0)
    tail = dummy
    
    current1, current2 = head1, head2

    while current1 and current2:
        if current1.data == current2.data:
            tail.next = Node(current1.data)
            tail = tail.next
            current1 = current1.next
            current2 = current2.next
        elif current1.data < current2.data:
            current1 = current1.next
        else:
            current2 = current2.next

    return dummy.next

def create_linked_list(array):
        head = Node(array[0])
        current = head
        for val in array[1:]:
            current.next = Node(val)
            current = current.next
        return head

def print_linked_list(head):
    current = head
    result = []
    while current:
        print(current.data, end = "->")
        current = current.next
    print("->".join(result) + "->NULL" if result else "NULL")

elements1 = list(map(int, input("Enter the elements of the 1st linked list : ").split()))
elements2 = list(map(int, input("Enter the elements of the 2nd linked list : ").split()))

head1 = create_linked_list(elements1)
head2 = create_linked_list(elements2)

result = intersect_sorted_lists(head1, head2)
print_linked_list(result)
