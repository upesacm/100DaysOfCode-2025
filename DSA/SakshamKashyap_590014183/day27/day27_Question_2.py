class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
        self.prev = None

class Doubly_linked_list:
    def __init__(self):
        self.head = None
    
    def insertion(self, value):
        New_Node = Node(value)
        if self.head is None:
            self.head = New_Node
            return
        current_Node = self.head
        while current_Node.next:
            current_Node = current_Node.next
        current_Node.next = New_Node
        New_Node.prev = current_Node

    def traversing(self):
        if self.head is None:
            print("List is empty")
            return
        current_Node = self.head
        while current_Node:
            print(f"{current_Node.data} <-> ",end = " ")
            current_Node = current_Node.next
        print("NULL")
    def reverse(self):
        tail = None
        if self.head is None:
            print("List is empty")
            return
        current_Node = self.head
        while current_Node.next:
            current_Node = current_Node.next
        while current_Node:
            print(f"{current_Node.data} <-> ",end = " ")
            current_Node = current_Node.prev
        print("NULL")
def main():
    My_Doubly_list = Doubly_linked_list()
    while True:
        try:
            data  = int(input("Enter the data to insert in doubly linked list: "))
            My_Doubly_list.insertion(data)
        except ValueError:
            print("Enter Only integer value please!")
        
        choice = input("Do you want to continue insert data in linked list? (yes/no): ").strip().lower()
        if choice not in ["y","yes"]:
            break
    
    print("\nThe Doubly Linked list is:")
    My_Doubly_list.traversing()
    print("\nThe Reverse of Doubly Linked list is:")
    My_Doubly_list.reverse()

if __name__ == "__main__":
    main()
    
