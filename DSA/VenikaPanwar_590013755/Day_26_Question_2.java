import java.util.*;

public class Day_26_Question_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node l1 = buildList(sc, "List 1");
        Node l2 = buildList(sc, "List 2");

        Node union = makeUnion(l1, l2);
        System.out.print("Union: ");
        printList(union);
    }

    public static Node makeUnion(Node l1, Node l2) {
        boolean[] present = new boolean[10001];

        Node temp = l1;
        while (temp != null) {
            present[temp.data] = true;
            temp = temp.next;
        }

        temp = l2;
        while (temp != null) {
            present[temp.data] = true;
            temp = temp.next;
        }

        Node head = null, tail = null;
        for (int i = 0; i < present.length; i++) {
            if (present[i]) {
                Node node = new Node(i);
                if (head == null) head = tail = node;
                else {
                    tail.next = node;
                    tail = node;
                }
            }
        }

        return head;
    }

    public static Node buildList(Scanner sc, String label) {
        System.out.print("Enter number of nodes for " + label + ": ");
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
