import java.util.Scanner;

class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class PrintLinkedList {

    
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


    public static void printLinkedList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println(); 
    }

    public static void main(String[] args) {
        ListNode head = createLinkedList();

        if (head == null) {
            System.out.println("Linked list is empty.");
        } else {
            printLinkedList(head);
        }
    }
}
