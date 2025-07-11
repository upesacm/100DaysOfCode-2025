import java.util.*;

public class Day_25_Question_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node head1 = createLinkedList(sc, "List 1");
        Node head2 = createLinkedList(sc, "List 2");

        Node dummy = new Node(-1), tail = dummy;
        Node a = head1, b = head2;

        while (a != null && b != null) {
            if (a.data == b.data) {
                tail.next = new Node(a.data);
                tail = tail.next;
                a = a.next;
                b = b.next;
            } else if (a.data < b.data) {
                a = a.next;
            } else {
                b = b.next;
            }
        }

        System.out.print("Intersection: ");
        Node temp = dummy.next;
        if (temp == null) System.out.println("Empty");
        else {
            while (temp != null) {
                System.out.print(temp.data + " ");
                temp = temp.next;
            }
        }
    }

    static Node createLinkedList(Scanner sc, String label) {
        System.out.print("Enter number of nodes for " + label + ": ");
        int n = sc.nextInt();
        Node head = null, tail = null;
        System.out.println("Enter " + n + " sorted elements:");
        for (int i = 0; i < n; i++) {
            Node node = new Node(sc.nextInt());
            if (head == null) head = tail = node;
            else {
                tail.next = node;
                tail = node;
            }
        }
        return head;
    }
}
