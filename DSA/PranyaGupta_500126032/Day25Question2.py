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
    
    def intersection(self, head1, head2):
        curr1 = head1
        curr2 = head2
        res = LinkedList()
        while(curr1 and curr2):
            if curr1.data == curr2.data:
                res.add(curr1.data)
                curr2= curr2.next 
                curr1 = curr1.next 
            elif curr1.data<curr2.data:
                curr1 = curr1.next
            else:
                curr2 = curr2.next        
        self.printlist(res.head)    
            

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
    l.intersection(l1.head1, l2.head2)
if __name__ == "__main__":
    main()