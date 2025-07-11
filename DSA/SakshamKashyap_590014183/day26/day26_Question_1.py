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
    def swap_kth_node(self, k):
        if self.head is None:
            return "List is empty"

        count = 0
        currentNode = self.head
        while currentNode:
            count += 1
            currentNode = currentNode.next

        if k > count:
            return "false"

        if 2*k - 1 == count:
            return "true"
        
        prev_b = None
        current_b = self.head
        for i in range(k - 1):
            prev_b = current_b
            current_b = current_b.next

        prev_e = None
        current_e = self.head
        for i in range(count - k):
            prev_e = current_e
            current_e = current_e.next

        if prev_b:
            prev_b.next = current_e
        else:
            self.head = current_e

        if prev_e:
            prev_e.next = current_b
        else:
            self.head = current_b

        current_b.next, current_e.next = current_e.next, current_b.next

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

    k = int(input("Enter the number of node u want to swap from beginning and end: "))

    My_Linked_List.swap_kth_node(k)

    print("\nModify Linked List: ")
    My_Linked_List.traversing()


if __name__ == "__main__":
    main()