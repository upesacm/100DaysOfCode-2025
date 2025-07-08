import java.util.*;

public class Day_23_Question_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node head = null, tail = null;

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            Node newNode = new Node(sc.nextInt());
            if (head == null) {
                head = tail = newNode;
            } else {
                tail.next = newNode;
                tail = newNode;
            }
        }

        System.out.print("Enter value of k: ");
        int k = sc.nextInt();

        Node first = head, second = head;
        for (int i = 0; i < k; i++) {
            if (second == null) {
                System.out.println("-1");
                return;
            }
            second = second.next;
        }

        while (second != null) {
            first = first.next;
            second = second.next;
        }

        if (first != null)
            System.out.println("Kth from end: " + first.data);
        else
            System.out.println("-1");
    }
}
