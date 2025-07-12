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
            return "List is empty"
        current_Node = self.head
        while current_Node:
            print(f"{current_Node.data} <-> ",end = " ")
            current_Node = current_Node.next
        print("NULL")
    def delete(self,kth_Node):
        if self.head is None:
            return "List is empty"
        current_Node = self.head
        for _ in range(1,kth_Node):
            current_Node = current_Node.next
        current_Node.prev.next = current_Node.next

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
    k = int(input("Enter the element u want to delete(Give the specific position of node): "))
    My_Doubly_list.delete(k)
    print("\n The updated Linked List: ")
    My_Doubly_list.traversing()















if __name__ == "__main__":
    main()
    
