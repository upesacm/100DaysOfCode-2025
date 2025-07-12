class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def remove_every_kth_node(head, k):
    if k <= 0 or head is None:
        return head
    
    if k == 1:
        return None
    
    current = head
    prev = None 
    count = 1

    while current:
        if count % k == 0:
            prev.next = current.next
            current = current.next
        else:
            prev = current 
            current = current.next
        count += 1

    return head

def build_linked_list(array):
    if not array:
        return None
    
    head = Node(array[0])
    current = head
    for val in array[1:]:
        new_node = Node(val)
        current.next = new_node
        new_node.prev = current
        current = new_node
    return head

def print_linked_list(head):
    result = []
    while head:
        result.append(str(head.data))
        head = head.next
    print("->".join(result))

LinkedList = list(map(int, input("Enter the elements of the linked list separated by spaces : ").split()))
k = int(input("Enter k : "))

head = build_linked_list(LinkedList)
head = remove_every_kth_node(head, k)

print_linked_list(head)
