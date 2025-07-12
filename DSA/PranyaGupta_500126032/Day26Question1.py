class node:
    def __init__(self, data):
        self.next = None
        self.data = data
class LinkedList:
    def __init__(self):
        self.head = None
    def add(self, data):
        new_node = node(data)
        if not self.head:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node
    def length(self,head):
        l = 0
        curr = head
        while curr:
            l+=1
            curr= curr.next
        return l 
    def printlist(self, head):
        current = head
        while current:
            print(current.data, end=" ")
            current = current.next     
         
    def swapkth(self, head, k):
        l = self.length(head)
        if k>l or 2*k-1 == l:
            return head
        if k == l-k:
            return head
        lcurr = head
        lprev = None
        rcurr = head
        rprev = None
        for i in range(k-1):
            lprev = lcurr
            lcurr = lcurr.next
        for i in range(l-k):
            rprev = rcurr
            rcurr = rcurr.next
        if lprev:  
            lprev.next = rcurr
        else:
            head = rcurr
        
        if rprev:
            rprev.next = lcurr
        else:
            head = lcurr    
        temp = lcurr.next
        lcurr.next = rcurr.next
        rcurr.next = temp
        
        self.printlist(head)
def main():
    user_input = input("Enter elements of the linked list (with space in between): ")
    arr = list(map(int, user_input.strip().split()))
    k = int(input("Enter k: "))
    l = LinkedList()
    for n in arr:
        l.add(n)
    l.swapkth(l.head, k)
    
if __name__ == "__main__":
    main()