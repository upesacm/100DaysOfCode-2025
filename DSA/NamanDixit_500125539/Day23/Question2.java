import java.util.*;

class Question2 {

    // Node class
    static class SinglyLinkedListNode {
        int data;
        SinglyLinkedListNode next;

        SinglyLinkedListNode(int nodeData) {
            this.data = nodeData;
            this.next = null;
        }
    }

    // Head of the list
    SinglyLinkedListNode head;

    // Method to remove duplicates from sorted list
    public static SinglyLinkedListNode removeDuplicates(SinglyLinkedListNode list) {
        if (list == null)
            return null;

        SinglyLinkedListNode temp = list;

        while (temp.next != null) {
            if (temp.data == temp.next.data) {
                temp.next = temp.next.next; // Skip duplicate
            } else {
                temp = temp.next;
            }
        }

        return list;
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

    // Main method
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Question2 list = new Question2();

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

        list.head = removeDuplicates(list.head); // Remove duplicates
        list.printList(list.head);
    }
}
