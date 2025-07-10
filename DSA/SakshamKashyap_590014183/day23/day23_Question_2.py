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
    def delete_duplicate(self):
        if self.head is None:
            print("The list is empty.")
            return
        duplicate = set()
        current = self.head
        prev = None
        while current:
            if current.data in duplicate:
                prev.next = current.next
            else:
                duplicate.add(current.data)
                prev = current
            current = current.next

def main():
    My_Linked_List = Linked_List()
    print("Please enter the sorted element in linked list.")
    while True:
        try:
            data = int(input("Enter data to insert into Linked List: "))
            My_Linked_List.insertion(data)
        except ValueError:
            print("Enter the correct input!")
            continue

        choice = input("Do you want to insert more data? (yes/no): ").strip().lower()
        if choice not in ['yes', 'y']:
            break

    print("\nThe Linked list is:")
    My_Linked_List.traversing()

    print("\nLinked list after deleting duplicate is:")
    My_Linked_List.delete_duplicate()

    My_Linked_List.traversing()
if __name__ == "__main__":
    main()