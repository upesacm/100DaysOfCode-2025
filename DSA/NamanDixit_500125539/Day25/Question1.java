import java.util.Scanner;

public class Question1 {

    static class SinglyLinkedListNode {
        int data;
        SinglyLinkedListNode next;

        SinglyLinkedListNode(int nodeData) {
            this.data = nodeData;
            this.next = null;
        }
    }

    SinglyLinkedListNode head;

    boolean isPalindrome(SinglyLinkedListNode head) {
        // Find the middle
        SinglyLinkedListNode fast = head, slow = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }

        if (fast != null) { // odd nodes: skip the middle node
            slow = slow.next;
        }

        // Reverse the second half
        slow = reverseList(slow);
        fast = head;

        // Compare the first and second halves
        while (slow != null) {
            if (fast.data != slow.data)
                return false;
            fast = fast.next;
            slow = slow.next;
        }

        return true;
    }

    // Function to reverse a linked list
    SinglyLinkedListNode reverseList(SinglyLinkedListNode head) {
        SinglyLinkedListNode prev = null;
        while (head != null) {
            SinglyLinkedListNode nextNode = head.next;
            head.next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Question1 list = new Question1();

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        if (n <= 0) {
            System.out.println("List is empty.");
            return;
        }

        System.out.print("Enter value for node 1: ");
        int value = sc.nextInt();
        list.head = new SinglyLinkedListNode(value);
        SinglyLinkedListNode current = list.head;

        for (int i = 2; i <= n; i++) {
            System.out.print("Enter value for node " + i + ": ");
            value = sc.nextInt();
            current.next = new SinglyLinkedListNode(value);
            current = current.next;
        }

        boolean result = list.isPalindrome(list.head);
        System.out.println(result);
    }
}
