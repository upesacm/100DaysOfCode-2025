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

    def delete_at_position(self, position):
        if not self.head:
            return None
        
        current = self.head
        
        if position == 1:
            self.head = current.next
            if self.head:
                self.head.prev = None
            return self.head
            
        for _ in range(position - 1):
            if not current:
                return self.head
            current = current.next
            
        if not current:
            return self.head
            
        if current.prev:
            current.prev.next = current.next
        if current.next:
            current.next.prev = current.prev
            
        return self.head

    def display(self):
        nodes = []
        current = self.head
        while current:
            nodes.append(str(current.data))
            current = current.next
        print(" <--> ".join(nodes))

dll = DoublyLinkedList()
dll.append(10)
dll.append(20)
dll.append(30)

print("Input:")
dll.display()

position = 2
dll.delete_at_position(position)

print("\nOutput:")
dll.display()