
import java.util.Scanner;

public class Question3{
    static class Node {

        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    Node head;

    // Append a node to the list
    public void append(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }

        Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = newNode;
    }

    // Delete a node at a specific position (1-based index)
    public void deleteAtPosition(int position) {
        if (head == null) {
            System.out.println("List is already empty!");
            return;
        }

        Node current = head;

        if (position == 1) {
            head = current.next;
            current = null;
            return;
        }

        Node previous = null;
        for (int i = 1; i < position && current != null; i++) {
            previous = current;
            current = current.next;
        }

        if (current == null) {
            System.out.println("Position out of bounds!");
            return;
        }

        previous.next = current.next;
        current = null;
    }

    // Print the linked list
    public void printList() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + (temp.next != null ? " -> " : ""));
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Question3 list = new Question3();
        Scanner sc = new Scanner(System.in);

        // Get number of nodes
        System.out.print("Enter the number of nodes: ");
        int n = sc.nextInt();

        if (n <= 0) {
            System.out.println("List is empty.");
            return;
        }

        // Input list values
        for (int i = 1; i <= n; i++) {
            System.out.print("Enter value for node " + i + ": ");
            int value = sc.nextInt();
            list.append(value);
        }

        // Show original list
        System.out.println("\nOriginal List:");
        list.printList();

        // Ask for position to delete
        System.out.print("Enter the position of node to delete: ");
        int position = sc.nextInt();

        // Delete the node and print updated list
        list.deleteAtPosition(position);

        System.out.println("\nModified List:");
        list.printList();
    }
}
