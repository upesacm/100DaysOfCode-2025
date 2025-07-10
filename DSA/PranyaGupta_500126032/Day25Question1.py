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
         
    def reverse(self, head):
        prev = None
        current = self.head
        nxt = None
        while current:
            nxt = current.next
            newnode = node(current.data)
            newnode.next = prev
            prev = newnode
            current = nxt  
        return prev 
    def palindrome(self, head):
        head2 = self.reverse(head)
        head1 = self.head
        curr1 = head1
        curr2 = head2
        while curr1 and curr2:
            if curr1.data != curr2.data:
                return False
            curr1=curr1.next
            curr2=curr2.next
        return True             



def main():
    user_input = input("Enter elements of the linked list (with space in between): ")
    arr = list(map(int, user_input.strip().split()))
    l = LinkedList()
    for n in arr:
        l.add(n)
    result = l.palindrome(l.head)
    print(result)
if __name__ == "__main__":
    main()