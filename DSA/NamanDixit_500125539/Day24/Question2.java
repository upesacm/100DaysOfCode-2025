import java.util.*;

public class Question2 {

    // Node class
    static class SinglyLinkedListNode {
        int data;
        SinglyLinkedListNode next;

        SinglyLinkedListNode(int nodeData) {
            this.data = nodeData;
            this.next = null;
        }
    }

    SinglyLinkedListNode head;

    // Function to delete nodes in pattern: Keep M, Delete N
    public SinglyLinkedListNode deleteNodesInPattern(SinglyLinkedListNode head, int M, int N) {
        if (head == null || M == 0) return null;

        SinglyLinkedListNode current = head;

        while (current != null) {
            // Skip M nodes (keep)
            for (int i = 1; i < M && current != null; i++) {
                current = current.next;
            }

            // If we've reached end of list, break
            if (current == null) break;

            // Delete N nodes
            SinglyLinkedListNode temp = current.next;
            for (int i = 1; i <= N && temp != null; i++) {
                temp = temp.next;
            }

            // Connect M-th node to (M+N+1)-th node
            current.next = temp;
            current = temp;
        }

        return head;
    }

    // Print the linked list
    public void printList(SinglyLinkedListNode head) {
        SinglyLinkedListNode current = head;
        while (current != null) {
            System.out.print(current.data);
            if (current.next != null) System.out.print(" -> ");
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Question2 list = new Question2();

        // Input: number of nodes
        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        if (n <= 0) {
            System.out.println("List is empty.");
            return;
        }

        // Input: values of the linked list
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

        // Input: M and N
        System.out.print("Enter M (nodes to keep): ");
        int M = sc.nextInt();

        System.out.print("Enter N (nodes to delete): ");
        int N = sc.nextInt();

        // Apply pattern deletion
        list.head = list.deleteNodesInPattern(list.head, M, N);

        // Output after
        list.printList(list.head);
    }
}
