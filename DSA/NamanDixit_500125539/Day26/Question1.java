import java.util.Scanner;

public class Question1 {

    static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
            this.next = null;
        }
    }

    // Swap nodes in pairs; return true if any swap occurred
    public static boolean swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            System.out.println("After swapping in pairs: ");
            printList(head);
            return false;
        }

        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode point = dummy;
        boolean swapped = false;

        while (point.next != null && point.next.next != null) {
            ListNode swap1 = point.next;
            ListNode swap2 = point.next.next;

            // Swap pointers
            swap1.next = swap2.next;
            swap2.next = swap1;
            point.next = swap2;

            point = swap1;
            swapped = true;
        }

        // Print final list after swapping
        System.out.println("After swapping in pairs:");
        printList(dummy.next);

        return swapped;
    }

    // Print the linked list
    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println();
    }

    // Main method: takes input from user
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        if (n <= 0) {
            System.out.println("List is empty.");
            System.out.println("Swap occurred? false");
            return;
        }

        System.out.println("Enter node values:");
        ListNode head = new ListNode(sc.nextInt());
        ListNode current = head;

        for (int i = 1; i < n; i++) {
            current.next = new ListNode(sc.nextInt());
            current = current.next;
        }

        System.out.print("Original list: ");
        printList(head);

        boolean result = swapPairs(head);
        System.out.println(result);
    }
}
