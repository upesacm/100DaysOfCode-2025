class node:
    def __init__(self, data):
        self.next = None
        self.prev = None
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
        new_node.prev = current
    def printlist(self, head):
        current = head
        while current:
            print(current.data, end=" ")
            current = current.next

    def length(self,head):
        l = 0
        curr = head
        while curr:
            l+=1
            curr= curr.next
        return l
            
    def deletenode(self, head, pos):
        if not head:
            return None
        
        if pos == 1:
            head = head.next
            if head:
                head.prev = None
            return head
        i = 1
        current = head
        prevn = None
        while  i<pos and current:
            current = current.next
            i+=1
        if not current:
            return head
        if current.next:
            current.next.prev = current.prev
        if current.prev:
            current.prev.next = current.next

        return head
    
    def deletek(self, head, k):    
        if k <= 0:
            return head
        pos = k
        c = 0

        while True:
            l = self.length(head)
            if pos - c> l:
                break
            head = self.deletenode(head, pos - c)
            count_deleted += 1
            pos += k

        return head     


def main():
    user_input = input("Enter elements of the linked list (with space in between): ")
    arr = list(map(int, user_input.strip().split()))
    k = int(input("Enter k: "))
    l = LinkedList()
    for num in arr:
        l.add(num)
    res = l.deletek(l.head,k)
    l.printlist(res)
if __name__ == "__main__":
    main()