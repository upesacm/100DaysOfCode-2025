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
    def palindrome_linked_list(self):
        reverse_stack = []
        if self.head is None:
            return "List is empty."
        current_node = self.head
        while current_node:
            reverse_stack.append(current_node.data)
            current_node = current_node.next
        if reverse_stack == reverse_stack[::-1]:
            return "true"
        else:
            return "false"        
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
    # check the linked list is palindrome or not
    result = My_Linked_List.palindrome_linked_list()
    print(f"\n{result}")

if __name__ == "__main__":
    main()