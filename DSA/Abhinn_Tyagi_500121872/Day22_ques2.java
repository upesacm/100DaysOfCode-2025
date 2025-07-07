import java.util.Scanner;

class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class CountKeyInLinkedList {

  
    public static ListNode createLinkedList() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter elements of the linked list (type -1 to stop):");

        ListNode head = null, tail = null;

        while (true) {
            int input = scanner.nextInt();
            if (input == -1) break;

            ListNode newNode = new ListNode(input);
            if (head == null) {
                head = newNode;
                tail = head;
            } else {
                tail.next = newNode;
                tail = newNode;
            }
        }

        return head;
    }


    public static int countOccurrences(ListNode head, int key) {
        int count = 0;

        while (head != null) {
            if (head.val == key) {
                count++;
            }
            head = head.next;
        }

        return count;
    }

    
    public static void printList(ListNode head) {
        System.out.print("Linked List: ");
        while (head != null) {
            System.out.print(head.val);
            if (head.next != null) System.out.print(" -> ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        ListNode head = createLinkedList();

        if (head == null) {
            System.out.println("Linked list is empty.");
            return;
        }

        printList(head);

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter key to count: ");
        int key = scanner.nextInt();

        int occurrences = countOccurrences(head, key);
        System.out.println("Occurrences of " + key + ": " + occurrences);
    }
}
