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
def addition_list(a,b):
    count_a = 0
    count_b = 0
    sum_a = 0
    sum_b = 0
    total_sum = 0
    current_node_a = a
    current_node_b = b
    while current_node_a:
        count_a += 1
        current_node_a = current_node_a.next
    while current_node_b:
        count_b += 1
        current_node_b = current_node_b.next
    count_a -= 1
    count_b -= 1
    current_node_aa = a
    current_node_bb = b
    while current_node_aa:
        sum_a += (current_node_aa.data) * (10**count_a)
        current_node_aa = current_node_aa.next
        count_a -= 1
    while current_node_bb:
        sum_b += (current_node_bb.data) * (10**count_b)
        current_node_bb = current_node_bb.next
        count_b -= 1
    total_sum = sum_a + sum_b  
    return total_sum     
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
    sum = addition_list(My_Linked_List_1.head,My_Linked_List_2.head)
    My_string = str(sum)
    for num in My_string:
        My_Linked_List_3.insertion(num)
    My_Linked_List_3.traversing() 
if __name__ == "__main__":
    main()