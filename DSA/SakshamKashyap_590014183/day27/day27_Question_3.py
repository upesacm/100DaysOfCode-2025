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
            return "List is empty."
        current = self.head
        while current:
            print(f"{current.data} -> ",end="")
            current = current.next
        print("NULL")
    def deleted_every_kth(self,k):
        if self.head is None:
            print("The list is empty!")
            return
        if k <= 0:
            print("Invalid k.")
            return
        if k == 1:
            self.head = None
            return
        current = self.head
        prev = None
        count = 1

        while current:
            if count % k == 0:
                if prev:
                    prev.next = current.next
                    current = prev.next
                else:
                    self.head = current.next
                    current = self.head
                count += 1
                continue
            prev = current
            current = current.next
            count += 1  
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

    k = int(input("Enter every kth node you want to remove: "))

    My_Linked_List.deleted_every_kth(k)

    print("Updated Linked list is: ")
    My_Linked_List.traversing()


if __name__ == "__main__":
    main()