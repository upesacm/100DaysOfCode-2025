import java.util.Scanner;

public class Question3{

    // Node class
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // Function to sort the linked list of 0s, 1s, and 2s
    static Node segregate(Node head) {
        if (head == null || head.next == null) return head;

        Node zeroHead = new Node(-1), zeroTail = zeroHead;
        Node oneHead = new Node(-1), oneTail = oneHead;
        Node twoHead = new Node(-1), twoTail = twoHead;

        Node temp = head;

        while (temp != null) {
            Node nextNode = temp.next;
            temp.next = null;

            if (temp.data == 0) {
                zeroTail.next = temp;
                zeroTail = temp;
            } else if (temp.data == 1) {
                oneTail.next = temp;
                oneTail = temp;
            } else {
                twoTail.next = temp;
                twoTail = temp;
            }

            temp = nextNode;
        }

        // Merge the three lists
        if (oneHead.next == null) {
            zeroTail.next = twoHead.next;
        } else {
            zeroTail.next = oneHead.next;
            oneTail.next = twoHead.next;
        }

        // Return the new head
        return zeroHead.next;
    }

    // Function to print the list
    static void printList(Node head) {
        if (head == null) {
            System.out.println("Empty list");
            return;
        }
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }

    // Build list from user input
    static Node buildList(Scanner sc) {
        System.out.print("Enter the number of nodes: ");
        int n = sc.nextInt();

        if (n <= 0) return null;

        System.out.println("Enter " + n + " values (0, 1, or 2 only):");
        int val = sc.nextInt();
        Node head = new Node(val);
        Node tail = head;

        for (int i = 1; i < n; i++) {
            val = sc.nextInt();
            if (val < 0 || val > 2) {
                System.out.println("Invalid value! Only 0, 1, or 2 are allowed.");
                i--; // redo this iteration
                continue;
            }
            tail.next = new Node(val);
            tail = tail.next;
        }

        return head;
    }

    // Main method
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Node head = buildList(sc);

        System.out.print("Original List: ");
        printList(head);

        Node sorted = segregate(head);
        printList(sorted);
    }
}
