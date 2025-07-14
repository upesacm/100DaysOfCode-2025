class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

def create_linked_list(array):
        dummy = ListNode()
        current = dummy
        for val in array:
            current.next = ListNode(val)
            current = current.next
        return dummy.next

def print_linked_list(head):
    result = []
    while head:
        result.append(str(head.val))
        head = head.next
    print("->".join(result) if result else "NULL")

def delete_n_after_m(head, m, n):
    current = head
    while current:
         
        for i in range(1, m):
            if current is None:
                return head
            current = current.next

        if current is None:
            break

        temp = current.next
        for i in range(n):
            if temp is None:
                break
            temp = temp.next

            current.next = temp

            current = temp
    
    return head

elements = list(map(int, input("Enter the elements of the linked list : ").split()))
n = int(input("Enter the value of n : "))
m = int(input("Enter the value of m : "))

head = create_linked_list(elements)

head = delete_n_after_m(head, m, n)

print_linked_list(head)
