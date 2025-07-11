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
    def printlist(self, head):
        current = head
        while current:
            print(current.data, end=" ")
            current = current.next   
    def insertnode(self, head, val):
        newnode = node(val)
        newnode.next = head
        return newnode
    def length(self,head):
        l = 0
        curr = head
        while curr:
            l+=1
            curr= curr.next
        return l  
    def addition(self, h1, h2):
        l1 = self.length(h1)
        l2 = self.length(h2)
        #adding leaading 0's if required
        if l1>l2:
            for _ in range(l1-l2):
                h2 = self.insertnode(h2,0)
        elif l1<l2:
            for _ in range(l2-l1):
                h1 = self.insertnode(h1,0)
        #performing addition
        s1 = ""
        s2 = ""
        c1 = h1
        c2 = h2
        while c1 and c2:
            s1+=str(c1.data)
            s2+=str(c2.data)
            c1 = c1.next
            c2 = c2.next
        res  = int(s1)+int(s2)
        resl = LinkedList()
        for n in str(res):
            resl.add(int(n))
        self.printlist(resl.head)      
                   




def main():
    user_input1 = input("Enter elements of the linked list1 (with space in between): ")
    arr1 = list(map(int, user_input1.strip().split()))
    l1 = LinkedList()
    for n1 in arr1:
        l1.add(n1)
    user_input2 = input("Enter elements of the linked list2 (with space in between): ")
    arr2 = list(map(int, user_input2.strip().split()))
    l2 = LinkedList()
    for n2 in arr2:
        l2.add(n2)
    l = LinkedList()   
    l.addition(l1.head, l2.head)
if __name__ == "__main__":
    main()