import java.util.*;

public class Day_26_Question_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node head = buildList(sc);

        System.out.print("Enter value of k: ");
        int k = sc.nextInt();

        Node result = swapKth(head, k);
        printList(result);
    }

    public static Node swapKth(Node head, int k) {
        if (head == null) return null;

        int length = 0;
        Node temp = head;
        while (temp != null) {
            length++;
            temp = temp.next;
        }

        if (k > length) return head;
        if (2 * k - 1 == length) return head;

        Node firstPrev = null, first = head;
        for (int i = 1; i < k; i++) {
            firstPrev = first;
            first = first.next;
        }

        Node secondPrev = null, second = head;
        for (int i = 1; i < length - k + 1; i++) {
            secondPrev = second;
            second = second.next;
        }

        if (firstPrev != null) firstPrev.next = second;
        if (secondPrev != null) secondPrev.next = first;

        Node tempNode = first.next;
        first.next = second.next;
        second.next = tempNode;

        if (k == 1) return second;
        if (k == length) return first;
        return head;
    }

    public static Node buildList(Scanner sc) {
        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();
        Node head = null, tail = null;
        System.out.println("Enter elements:");
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

    public static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }
}
