import java.util.*;

public class Day_24_Question_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node head = null, tail = null;

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();
        System.out.println("Enter node values:");
        for (int i = 0; i < n; i++) {
            Node node = new Node(sc.nextInt());
            if (head == null) {
                head = tail = node;
            } else {
                tail.next = node;
                tail = node;
            }
        }

        System.out.print("Enter position to delete (1-based): ");
        int x = sc.nextInt();

        if (x <= 0) {
            System.out.println("Invalid position.");
            return;
        }

        if (x == 1) {
            head = head.next;
        } else {
            Node current = head;
            for (int i = 1; i < x - 1 && current != null; i++) {
                current = current.next;
            }

            if (current == null || current.next == null) {
                System.out.println("Position out of range.");
                return;
            }

            current.next = current.next.next;
        }

        System.out.print("Updated list: ");
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }
}
