class ListNode:
    def __init__(self, val=0, next=None):
        self.val=val 
        self.next=next
    
def build_linked_list(values):
    if not values:
        return None
    head = ListNode(values[0])
    current = head 

    for val in values[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

def print_linked_list(head):
    current = head
    while current:
        print(current.val, end=" -> ")
        current = current.next
    print()

def count_frequency(head, key):
    count = 0
    current = head
    while current:
        if current.val == key:
            count += 1
        current = current.next
    return count
    
values = [1, 2, 1, 2, 1, 3, 1]   
key = 1                          

head = build_linked_list(values)

print("Linked List:")
print_linked_list(head)

frequency = count_frequency(head, key)
print(f"Occurrences of {key}:", frequency)