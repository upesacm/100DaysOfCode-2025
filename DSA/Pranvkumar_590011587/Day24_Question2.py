class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def print_list(head):
    while head:
        print(head.data, end=" -> ")
        head = head.next
    print("NULL")

# 2. Delete N nodes after M nodes
def delete_n_after_m(head, m, n):
    current = head
    while current:
        for i in range(1, m):
            if current is None:
                return head
            current = current.next
        if current is None:
            break
        temp = current.next
        for i in range(n):
            if temp is None:
                break
            temp = temp.next
        current.next = temp
        current = temp
    return head

# --- Test Cases ---
# Example 1: 9->1->3->5->9->4->10->1, m = 2, n = 1
list = Node(9)
list.next = Node(1)
list.next.next = Node(3)
list.next.next.next = Node(5)
list.next.next.next.next = Node(9)
list.next.next.next.next.next = Node(4)
list.next.next.next.next.next.next = Node(10)
list.next.next.next.next.next.next.next = Node(1)
print("Original:")
print_list(list)
list = delete_n_after_m(list, m=2, n=1)
print("After deleting 1 node after every 2 nodes:")
print_list(list)
# Example 2: 1->2->3->4->5->6, m = 6, n = 1
list1 = Node(1)
list1.next = Node(2)
list1.next.next = Node(3)
list1.next.next.next = Node(4)
list1.next.next.next.next = Node(5)
list1.next.next.next.next.next = Node(6)
print("\nOriginal:")
print_list(list1)
list1 = delete_n_after_m(list1, m=6, n=1)
print("After deleting 1 node after every 6 nodes:")
print_list(list1)