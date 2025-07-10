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
def insertion_sort(a,b):
    dummy = Node(0)
    tail = dummy

    while(a and b):
        if (a.data == b.data):
            tail.next = Node(a.data)
            tail = tail.next
            a = a.next
            b = b.next

        elif(a.data < b.data):
            a = a.next
        else:
            b = b.next
    return(dummy.next)
def printList(node):
    while (node != None):
        print(f"{node.data} ->", end=" ")
        node = node.next
    print("NULL")
def main():
    My_Linked_List_1 = Linked_List()
    My_Linked_List_2 = Linked_List()
    print("Request the user to enter only sorted element in linked list.")
    while True:
        try:
            data = int(input("Enter data to insert into Linked List 1: "))
            My_Linked_List_1.insertion(data)
        except ValueError:
            print("Enter the correct input!")
            continue

        choice = input("Would you like to add more data in Linked List 1? (yes/no): ").strip().lower()
        if choice not in ['yes', 'y']:
            break
    while True:
        try:
            data = int(input("Enter data to insert into Linked List 2: "))
            My_Linked_List_2.insertion(data)
        except ValueError:
            print("Enter the correct input.")
            continue
        choice = input("Would you like to add more data in Linked list 2? (yes/no): ").strip().lower()
        if choice not in ["yes","y"]:
            break
    node = insertion_sort(My_Linked_List_1.head,My_Linked_List_2.head)
    printList(node)
if __name__ == "__main__":
    main()