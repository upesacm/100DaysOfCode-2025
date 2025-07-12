import java.util.*;

public class Day_26_Question_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node head = buildList(sc);

        head = sortList(head);
        System.out.print("Sorted List: ");
        printList(head);
    }

    public static Node sortList(Node head) {
        int[] count = new int[3];
        Node temp = head;

        while (temp != null) {
            count[temp.data]++;
            temp = temp.next;
        }

        temp = head;
        int i = 0;
        while (temp != null) {
            if (count[i] == 0) i++;
            else {
                temp.data = i;
                count[i]--;
                temp = temp.next;
            }
        }

        return head;
    }

    public static Node buildList(Scanner sc) {
        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();
        Node head = null, tail = null;
        System.out.println("Enter values (only 0s, 1s, 2s):");
        for (int i = 0; i < n; i++) {
            int val = sc.nextInt();
            if (val < 0 || val > 2) {
                System.out.println("Invalid input. Only 0, 1, or 2 allowed.");
                return null;
            }
            Node node = new Node(val);
            if (head == null) head = tail = node;
            else {
                tail.next = node;
                tail = node;
            }
        }
        return head;
    }

    public static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }
}
