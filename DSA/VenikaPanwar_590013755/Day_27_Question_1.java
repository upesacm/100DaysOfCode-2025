import java.util.*;

public class Day_27_Question_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        DoublyNode head = createDoublyList(sc);

        System.out.print("Enter position to delete (1-based): ");
        int pos = sc.nextInt();

        head = deleteAtPosition(head, pos);
        printDoublyList(head);
    }

    static DoublyNode deleteAtPosition(DoublyNode head, int x) {
        if (head == null) return null;

        if (x == 1) {
            head = head.next;
            if (head != null) head.prev = null;
            return head;
        }

        DoublyNode current = head;
        for (int i = 1; i < x && current != null; i++) {
            current = current.next;
        }

        if (current == null) return head;

        if (current.prev != null)
            current.prev.next = current.next;

        if (current.next != null)
            current.next.prev = current.prev;

        return head;
    }

    static DoublyNode createDoublyList(Scanner sc) {
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        DoublyNode head = null, tail = null;
        System.out.println("Enter elements:");
        for (int i = 0; i < n; i++) {
            DoublyNode node = new DoublyNode(sc.nextInt());
            if (head == null) head = tail = node;
            else {
                tail.next = node;
                node.prev = tail;
                tail = node;
            }
        }
        return head;
    }

    static void printDoublyList(DoublyNode head) {
        while (head != null) {
            System.out.print(head.data);
            if (head.next != null) System.out.print(" <-> ");
            head = head.next;
        }
        System.out.println();
    }
}
