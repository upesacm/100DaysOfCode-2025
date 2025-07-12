class SingleNode:
    def __init__(self, data):
        self.data = data
        self.next = None

def removeKthNode(head, k):
    if k == 0:
        return head

    count = 1
    current = head
    prev = None

    while current:
        if count % k == 0:
            prev.next = current.next
        else:
            prev = current
        current = current.next
        count += 1

    return head

# Sample Test
def printSLL(head):
    while head:
        print(head.data, end=" -> " if head.next else "\n")
        head = head.next

s1 = SingleNode(1)
s2 = SingleNode(2)
s3 = SingleNode(3)
s4 = SingleNode(4)
s5 = SingleNode(5)
s6 = SingleNode(6)
s7 = SingleNode(7)
s8 = SingleNode(8)

s1.next = s2
s2.next = s3
s3.next = s4
s4.next = s5
s5.next = s6
s6.next = s7
s7.next = s8

head = removeKthNode(s1, 2)
printSLL(head)
