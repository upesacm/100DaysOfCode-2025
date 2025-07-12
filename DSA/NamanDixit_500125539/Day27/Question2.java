class Node {
    int data;
    Node next, prev;

    Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLinkedList {
    // Function to reverse the doubly linked list
    public Node reverseDLL(Node head) {
        if (head == null || head.next == null) {
            return head;
        }

        Node current = head;
        Node prev = null;

        while (current != null) {
            prev = current.prev;

            // Swap next and prev pointers
            current.prev = current.next;
            current.next = prev;

            // Move to next node (which is current.prev now)
            current = current.prev;
        }

        // After the loop, prev will point to the old second node
        // So head should be updated to prev.prev
        if (prev != null) {
            head = prev.prev;
        }

        return head;
    }

    // Utility to print the list
    public void printList(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    // Insert at end
    public Node insertAtEnd(Node head, int data) {
        Node newNode = new Node(data);
        if (head == null) {
            return newNode;
        }

        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }

        temp.next = newNode;
        newNode.prev = temp;
        return head;
    }
}

public class Question2 {
    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        DoublyLinkedList dll = new DoublyLinkedList();
        Node head = null;

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            System.out.print("Enter value: ");
            int val = sc.nextInt();
            head = dll.insertAtEnd(head, val);
        }

        dll.printList(head);

        head = dll.reverseDLL(head);

        dll.printList(head);
    }
}
