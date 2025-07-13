import java.util.*;

public class Day_27_Question_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        DoublyNode head = createDoublyList(sc);

        head = reverseList(head);
        printDoublyList(head);
    }

    static DoublyNode reverseList(DoublyNode head) {
        DoublyNode current = head, prev = null;
        while (current != null) {
            DoublyNode nextNode = current.next;
            current.next = current.prev;
            current.prev = nextNode;
            prev = current;
            current = nextNode;
        }
        return prev;
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
