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
    def sort_0_1_2(self):
        C0 = 0
        C1 = 0
        C2 = 0
        current_Node = self.head
        while current_Node:
            if current_Node.data == 0:
                C0 += 1
            elif current_Node.data == 1:
                C1 += 1
            else:
                C2 += 1 
            current_Node = current_Node.next

        current_Node = self.head
        for _ in range(C0):
            current_Node.data = 0
            current_Node = current_Node.next
        for _ in range(C1):
            current_Node.data = 1
            current_Node = current_Node.next
        for _ in range(C2):
            current_Node.data = 2
            current_Node = current_Node.next
        
def main():
    My_Linked_List = Linked_List()
    print("Only enter 0,1,2 as element in linked list.")
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
    My_Linked_List.sort_0_1_2()
    print("New Sorted linked list is: ")
    My_Linked_List.traversing()

if __name__ == "__main__":
    main()