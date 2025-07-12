
import java.util.Scanner;

class Node {

    int data;
    Node next, previous;

    Node(int data) {
        this.data = data;
        this.next = null;
        this.previous = null;
    }
}

class DoublyLinkedList {

    // Insert at the beginning
    public Node insert(int data, Node head) {
        Node newNode = new Node(data);
        if (head != null) {
            head.previous = newNode;
            newNode.next = head;
        }
        head = newNode;
        return head;
    }

    // Delete node at a given position
    public Node deleteNodeAtGivenPosition(Node head, int position) {
        if (head == null) {
            return head;
        }

        if (position == 1) {
            if (head.next != null) {
                head.next.previous = null;
            }
            return head.next;
        }

        Node node = head;
        while (node != null && position > 1) {
            node = node.next;
            position--;
        }

        if (node == null) {
            System.out.println("Element doesn't exist at the given position.");
            return head;
        }

        if (node.next != null) {
            node.next.previous = node.previous;
        }
        node.previous.next = node.next;

        return head;
    }

    // Display the list
    public void display(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}

public class Question1 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        DoublyLinkedList dll = new DoublyLinkedList();
        Node head = null;

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            System.out.print("Enter value: ");
            int value = sc.nextInt();
            head = dll.insert(value, head);
        }

        dll.display(head);

        System.out.print("Enter position to delete: ");
        int position = sc.nextInt();
        head = dll.deleteNodeAtGivenPosition(head, position);
        dll.display(head);
    }
}
