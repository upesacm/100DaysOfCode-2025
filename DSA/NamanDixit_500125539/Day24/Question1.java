import java.util.*;

public class Question1{
    static class SinglyLinkedListNode {
        int data;
        SinglyLinkedListNode next;

        SinglyLinkedListNode(int nodeData) {
            this.data = nodeData;
            this.next = null;
        }
    }

    SinglyLinkedListNode head;

    // Method to reverse between positions left and right (1-indexed)
    public SinglyLinkedListNode reverseBetween(SinglyLinkedListNode head, int left, int right) {
        // Create a dummy node to simplify edge cases
        SinglyLinkedListNode dummy = new SinglyLinkedListNode(0);
        dummy.next = head;

        // Step 1: Move to the node before 'left'
        SinglyLinkedListNode leftPre = dummy;
        for (int i = 1; i < left; i++) {
            leftPre = leftPre.next;
        }

        // Step 2: Start reversing
        SinglyLinkedListNode currNode = leftPre.next;
        SinglyLinkedListNode preNode = null;

        for (int i = 0; i <= right - left; i++) {
            SinglyLinkedListNode nextNode = currNode.next;
            currNode.next = preNode;
            preNode = currNode;
            currNode = nextNode;
        }

        // Step 3: Connect the reversed part with the rest of the list
        leftPre.next.next = currNode;
        leftPre.next = preNode;

        return dummy.next;
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

        System.out.print("Enter left index to reverse: ");
        int left = sc.nextInt();
        System.out.print("Enter right index to reverse: ");
        int right = sc.nextInt();
        list.head = list.reverseBetween(list.head, left, right);
        list.printList(list.head);
    }
}
