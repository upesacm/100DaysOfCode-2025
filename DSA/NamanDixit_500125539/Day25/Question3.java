import java.util.Scanner;

public class Question3 {

    static class SinglyLinkedListNode {
        int data;
        SinglyLinkedListNode next;

        SinglyLinkedListNode(int nodeData) {
            this.data = nodeData;
            this.next = null;
        }
    }

    // Method to add two numbers represented by linked lists
    public static SinglyLinkedListNode addTwoNumbers(SinglyLinkedListNode l1, SinglyLinkedListNode l2) {
        SinglyLinkedListNode head = null;
        SinglyLinkedListNode temp = null;
        int carry = 0;

        while (l1 != null || l2 != null || carry != 0) {
            int val1 = (l1 == null) ? 0 : l1.data;
            int val2 = (l2 == null) ? 0 : l2.data;

            int value = val1 + val2 + carry;
            SinglyLinkedListNode newNode = new SinglyLinkedListNode(value % 10);
            carry = value / 10; // maintain carry

            if (head == null) {
                head = newNode;
                temp = newNode;
            } else {
                temp.next = newNode;
                temp = temp.next;
            }

            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
        }

        return head;
    }

    // Helper method to create a linked list from user input
    public static SinglyLinkedListNode createList(Scanner sc, String name) {
        System.out.print("Enter number of nodes in " + name + ": ");
        int n = sc.nextInt();
        if (n <= 0) return null;

        System.out.print("Enter value for node 1: ");
        int val = sc.nextInt();
        SinglyLinkedListNode head = new SinglyLinkedListNode(val);
        SinglyLinkedListNode curr = head;

        for (int i = 2; i <= n; i++) {
            System.out.print("Enter value for node " + i + ": ");
            val = sc.nextInt();
            curr.next = new SinglyLinkedListNode(val);
            curr = curr.next;
        }

        return head;
    }

    // Helper method to print a linked list
    public static void printList(SinglyLinkedListNode head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input two numbers as linked lists
        SinglyLinkedListNode head1 = createList(sc, "List 1");
        SinglyLinkedListNode head2 = createList(sc, "List 2");

        // Add the two numbers
        SinglyLinkedListNode result = addTwoNumbers(head1, head2);

        // Output the result
        printList(result);
    }
}
