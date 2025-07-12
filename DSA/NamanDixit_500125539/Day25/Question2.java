import java.util.Scanner;

public class Question2 {

    static class SinglyLinkedListNode {
        int data;
        SinglyLinkedListNode next;

        SinglyLinkedListNode(int nodeData) {
            this.data = nodeData;
            this.next = null;
        }
    }

    SinglyLinkedListNode head;

    // Method to find intersection
    public static SinglyLinkedListNode findIntersection(SinglyLinkedListNode head1, SinglyLinkedListNode head2) {
        SinglyLinkedListNode t1 = head1;
        SinglyLinkedListNode t2 = head2;

        // Dummy node to simplify appending
        SinglyLinkedListNode resHead = new SinglyLinkedListNode(-1);
        SinglyLinkedListNode resTail = resHead;

        while (t1 != null && t2 != null) {
            if (t1.data == t2.data) {
                resTail.next = new SinglyLinkedListNode(t1.data);
                resTail = resTail.next;
                t1 = t1.next;
                t2 = t2.next;
            } else if (t1.data < t2.data) {
                t1 = t1.next;
            } else {
                t2 = t2.next;
            }
        }

        return resHead.next; // Return actual head (skipping dummy)
    }

    // Utility function to print a list
    public static void printList(SinglyLinkedListNode head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }

    // Utility to create list from user input
    public static SinglyLinkedListNode createList(Scanner sc, String listName) {
        System.out.print("Enter number of nodes in " + listName + ": ");
        int n = sc.nextInt();
        if (n <= 0) return null;

        System.out.print("Enter value for node 1: ");
        int value = sc.nextInt();
        SinglyLinkedListNode head = new SinglyLinkedListNode(value);
        SinglyLinkedListNode current = head;

        for (int i = 2; i <= n; i++) {
            System.out.print("Enter value for node " + i + ": ");
            value = sc.nextInt();
            current.next = new SinglyLinkedListNode(value);
            current = current.next;
        }

        return head;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Create first list
        SinglyLinkedListNode head1 = createList(sc, "List 1");

        // Create second list
        SinglyLinkedListNode head2 = createList(sc, "List 2");

        // Find and print intersection
        SinglyLinkedListNode intersection = findIntersection(head1, head2);
        printList(intersection);
    }
}
