import java.util.*;

public class Day_25_Question_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node head = createLinkedList(sc);

        if (head == null || head.next == null) {
            System.out.println("true");
            return;
        }

        Node slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        Node secondHalf = reverse(slow);
        Node firstHalf = head;

        boolean isPalindrome = true;
        while (secondHalf != null) {
            if (firstHalf.data != secondHalf.data) {
                isPalindrome = false;
                break;
            }
            firstHalf = firstHalf.next;
            secondHalf = secondHalf.next;
        }

        System.out.println(isPalindrome);
    }

    static Node reverse(Node head) {
        Node prev = null;
        while (head != null) {
            Node temp = head.next;
            head.next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }

    static Node createLinkedList(Scanner sc) {
        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();
        if (n <= 0) return null;

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
}
