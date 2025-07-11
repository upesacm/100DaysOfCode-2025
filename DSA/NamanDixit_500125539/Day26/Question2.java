import java.util.Scanner;

public class Question2 {

    // Definition for singly-linked list
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
            this.next = null;
        }
    }

    // Recursive method to merge two sorted lists
    public static ListNode mergeTwoLists(ListNode head1, ListNode head2) {
        if (head1 == null || head2 == null) {
            return (head1 == null) ? head2 : head1;
        }

        if (head1.val <= head2.val) {
            head1.next = mergeTwoLists(head1.next, head2);
            return head1;
        } else {
            head2.next = mergeTwoLists(head1, head2.next);
            return head2;
        }
    }

    // Helper method to print a linked list
    public static void printList(ListNode head) {
        if (head == null) {
            System.out.println("Empty list.");
            return;
        }

        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println();
    }

    // Helper method to build a linked list from user input
    public static ListNode buildListFromInput(Scanner sc, int listNumber) {
        System.out.print("Enter number of nodes in List " + listNumber + ": ");
        int n = sc.nextInt();

        if (n <= 0) {
            System.out.println("List " + listNumber + " is empty.");
            return null;
        }

        System.out.println("Enter " + n + " sorted values for List " + listNumber + ":");
        ListNode head = new ListNode(sc.nextInt());
        ListNode current = head;

        for (int i = 1; i < n; i++) {
            current.next = new ListNode(sc.nextInt());
            current = current.next;
        }

        return head;
    }

    // Main method
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Build both lists
        ListNode head1 = buildListFromInput(sc, 1);
        ListNode head2 = buildListFromInput(sc, 2);

        // Display both input lists
        System.out.print("List 1: ");
        printList(head1);

        System.out.print("List 2: ");
        printList(head2);

        // Merge the two lists
        ListNode merged = mergeTwoLists(head1, head2);

        // Display merged result
        printList(merged);
    }
}
