class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def deleteNodes(head, m, n):
    current = head
    while current:
        for _ in range(m - 1):
            if not current:
                break
            current = current.next
        if not current:
            break
        temp = current.next
        for _ in range(n):
            if not temp:
                break
            temp = temp.next
        current.next = temp
        current = temp
    return head

def printList(head):
    current = head
    while current:
        print(current.val, end=" -> " if current.next else "")
        current = current.next
    print()

def createList(arr):
    dummy = ListNode()
    current = dummy
    for val in arr:
        current.next = ListNode(val)
        current = current.next
    return dummy.next

if __name__ == "__main__":
    arr = [9, 1, 3, 5, 9, 4, 10, 1]
    m = 2
    n = 1
    head = createList(arr)
    
    print("Original list:")
    printList(head)
    
    result = deleteNodes(head, m, n)
    
    print("Modified list:")
    printList(result)