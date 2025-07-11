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
def union(head_1,head_2):
    union_value = set()
    if head_1 and head_2 is None:
        return "List is empty"
    current_node_1 = head_1
    current_node_2 = head_2
    while current_node_1:
        union_value.add(current_node_1.data)
        current_node_1 = current_node_1.next
    while current_node_2:
        union_value.add(current_node_2.data)
        current_node_2 = current_node_2.next
    return union_value
def main():
    My_Linked_List_1 = Linked_List()
    My_Linked_List_2 = Linked_List()
    My_Linked_List_3 = Linked_List()
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
    result = union(My_Linked_List_1.head , My_Linked_List_2.head)
    for num in result:
        My_Linked_List_3.insertion(num)
    print("\nthe union linked list is: ")
    My_Linked_List_3.traversing()
if __name__ == "__main__":
    main()