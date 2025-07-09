import java.util.*;

public class Question3 {
    static class SinglyLinkedListNode {
        int data;
        SinglyLinkedListNode next;

        SinglyLinkedListNode(int nodeData) {
            this.data = nodeData;
            this.next = null;
        }
    }

    SinglyLinkedListNode head;

    // Function to delete the middle node
    public SinglyLinkedListNode deleteMiddle(SinglyLinkedListNode head) {
        if (head == null || head.next == null) return null;
        if (head.next.next == null) {
            head.next = null;
            return head;
        }

        SinglyLinkedListNode slow = head, fast = head;
        SinglyLinkedListNode prev = null;

        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        // Delete the middle node
        prev.next = slow.next;
        slow.next = null;

        return head;
    }

    // Method to print the linked list
    public void printList(SinglyLinkedListNode head) {
        SinglyLinkedListNode current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Question3 list = new Question3();

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

        list.head = list.deleteMiddle(list.head); // Delete middle node
        list.printList(list.head);
    }
}
