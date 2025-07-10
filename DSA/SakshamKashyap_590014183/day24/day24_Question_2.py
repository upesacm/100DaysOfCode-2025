class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
class Linked_List:
    def __init__(self):
        self.head = None
    def insertion(self,data):
        New_Node = Node(data)
        if self.head is None:
            self.head = New_Node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = New_Node
    def traversing(self):
        if self.head is None:
            print("List is empty.")
            return
        current = self.head
        while current:
            print(f"{current.data} -> ",end="")
            current = current.next
        print("NULL")
    def delete_node(self,n,m):
        if self.head is None:
            return print("List is empty.")
        current = self.head
        while current:
            for i in range(1,m):
                if current is None:
                    return
                current = current.next
            if current and current.next is None:
                return
            temp = current.next
            for j in range(n):
                if temp is None:
                    break
                temp = temp.next
            current.next = temp
            current = temp
def main():
    My_Linked_List = Linked_List()

    while True:
        try:
            data = int(input("Enter data to insert into Linked List: "))
            My_Linked_List.insertion(data)
        except ValueError:
            print("Enter the correct input!")
            continue

        choice = input("Would you like to add more data? (yes/no): ").strip().lower()
        if choice not in ['yes', 'y']:
            break

    print("\nThe Linked list is:")
    My_Linked_List.traversing()
    n = int(input("Enter the numbers of node delete you want to delete: "))
    m= int(input("Enter the number of node you want to skip: "))
    My_Linked_List.delete_node(n,m)
    print("Linked list after deleting node: ")
    My_Linked_List.traversing()

if __name__ == "__main__":
    main()