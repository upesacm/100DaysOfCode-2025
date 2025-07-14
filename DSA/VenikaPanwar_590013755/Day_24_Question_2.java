import java.util.*;

public class Day_24_Question_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node head = null, tail = null;

        System.out.print("Enter number of elements in the list: ");
        int n = sc.nextInt();
        System.out.println("Enter list values:");
        for (int i = 0; i < n; i++) {
            Node node = new Node(sc.nextInt());
            if (head == null) {
                head = tail = node;
            } else {
                tail.next = node;
                tail = node;
            }
        }

        System.out.print("Enter M (nodes to keep): ");
        int m = sc.nextInt();
        System.out.print("Enter N (nodes to delete): ");
        int d = sc.nextInt();

        Node current = head;
        while (current != null) {
            for (int i = 1; i < m && current != null; i++) {
                current = current.next;
            }

            if (current == null) break;

            Node temp = current.next;
            for (int i = 0; i < d && temp != null; i++) {
                temp = temp.next;
            }

            current.next = temp;
            current = temp;
        }

        // Print result
        System.out.print("Modified list: ");
        Node ptr = head;
        while (ptr != null) {
            System.out.print(ptr.data + " ");
            ptr = ptr.next;
        }
    }
}
