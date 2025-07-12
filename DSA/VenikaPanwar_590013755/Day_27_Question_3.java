import java.util.*;

public class Day_27_Question_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node head = createSinglyList(sc);

        System.out.print("Enter value of k: ");
        int k = sc.nextInt();

        head = removeEveryKth(head, k);
        printSinglyList(head);
    }

    static Node removeEveryKth(Node head, int k) {
        if (k <= 1) return null;

        Node current = head;
        int count = 1;

        while (current != null && current.next != null) {
            if ((count + 1) % k == 0) {
                current.next = current.next.next;
                count++; // still move count forward for the removed node
            } else {
                current = current.next;
                count++;
            }
        }
        return head;
    }

    static Node createSinglyList(Scanner sc) {
        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();
        Node head = null, tail = null;
        System.out.println("Enter node values:");
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

    static void printSinglyList(Node head) {
        while (head != null) {
            System.out.print(head.data);
            if (head.next != null) System.out.print(" -> ");
            head = head.next;
        }
        System.out.println();
    }
}
