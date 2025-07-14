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
    def Kth_Node_End(self,k):
        count = 0
        if self.head is None:
            print("List is empty.")
            return
        current = self.head
        while current:
            count += 1
            current = current.next
        if k > count or k <= 0:
            print("-1")
            return
        New_count = count - k
        New_Current = self.head
        for i in range(New_count):
            New_Current = New_Current.next
        print(f"kth Node form end: {New_Current.data}")
def main():
    My_Linked_List = Linked_List()

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
    k = int(input("Enter the step you want to find node from end of linked list: "))
    My_Linked_List.Kth_Node_End(k)

if __name__ == "__main__":
    main()