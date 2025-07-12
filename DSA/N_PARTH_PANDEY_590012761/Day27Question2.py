class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = new_node
        new_node.prev = last

    def reverse(self):
        current = self.head
        temp = None
        
        while current:
            temp = current.prev
            current.prev = current.next
            current.next = temp
            current = current.prev
            
        if temp:
            self.head = temp.prev

    def display(self):
        nodes = []
        current = self.head
        while current:
            nodes.append(str(current.data))
            current = current.next
        print(" <-> ".join(nodes))

dll = DoublyLinkedList()
dll.append(10)
dll.append(20)
dll.append(30)
print("Input:")
dll.display()
dll.reverse()
print("\nOutput:")
dll.display()