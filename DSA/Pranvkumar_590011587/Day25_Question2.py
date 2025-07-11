class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
#  Problem 2: Intersection of Sorted Lists 
def getIntersection(head1: ListNode, head2: ListNode) -> ListNode:
    dummy = tail = ListNode(0)
    while head1 and head2:
        if head1.val == head2.val:
            tail.next = ListNode(head1.val)
            tail = tail.next
            head1 = head1.next
            head2 = head2.next
        elif head1.val < head2.val:
            head1 = head1.next
        else:
            head2 = head2.next
    return dummy.next

def build_linked_list(values):
    dummy = current = ListNode(0)
    for v in values:
        current.next = ListNode(v)
        current = current.next
    return dummy.next

def print_linked_list(head):
    vals = []
    while head:
        vals.append(str(head.val))
        head = head.next
    print(" -> ".join(vals))

if __name__ == "__main__":
    list1 = build_linked_list([1, 2, 3, 4, 6])
    list2 = build_linked_list([2, 4, 6, 8])
    print("Input: 1->2->3->4->6 and 2->4->6->8")
    result = getIntersection(list1, list2)
    print("Output:", end=" ")
    print_linked_list(result)  

    list3 = build_linked_list([10, 20, 40, 50])
    list4 = build_linked_list([15, 40])
    print("\nInput: 10->20->40->50 and 15->40")
    result = getIntersection(list3, list4)
    print("Output:", end=" ")
    print_linked_list(result) 
