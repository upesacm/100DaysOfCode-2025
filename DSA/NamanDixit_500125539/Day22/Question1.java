import java.util.Scanner;

public class Question1 {

    // Node class
    static class Node {
        int data;
        Node next;

        Node() {
            this.data = 0;
            this.next = null;
        }

        Node(int data) {
            this.data = data;
            this.next = null;
        }

        Node(int data, Node next) {
            this.data = data;
            this.next = next;
        }
    }

    // Method to find the middle node
    public static Node findMiddle(Node head) {
        Node slow = head;
        Node fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }

    // Main method with user input
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        if (n <= 0) {
            System.out.println("Linked list must have at least one node.");
            return;
        }

        System.out.print("Enter value for node 1: ");
        int value = sc.nextInt();
        Node head = new Node(value);
        Node current = head;

        for (int i = 2; i <= n; i++) {
            System.out.print("Enter value for node " + i + ": ");
            value = sc.nextInt();
            current.next = new Node(value);
            current = current.next;
        }

        Node middle = findMiddle(head);

        System.out.println("Middle element is: " + middle.data);
    }
}
