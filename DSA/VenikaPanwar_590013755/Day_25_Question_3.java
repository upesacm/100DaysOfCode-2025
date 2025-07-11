import java.util.*;

public class Day_25_Question_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node num1 = createLinkedList(sc, "First number");
        Node num2 = createLinkedList(sc, "Second number");

        Node dummy = new Node(-1), tail = dummy;
        int carry = 0;

        while (num1 != null || num2 != null || carry > 0) {
            int sum = carry;
            if (num1 != null) {
                sum += num1.data;
                num1 = num1.next;
            }
            if (num2 != null) {
                sum += num2.data;
                num2 = num2.next;
            }

            tail.next = new Node(sum % 10);
            carry = sum / 10;
            tail = tail.next;
        }

        System.out.print("Sum as Linked List: ");
        Node temp = dummy.next;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }

    static Node createLinkedList(Scanner sc, String label) {
        System.out.print("Enter number of digits for " + label + ": ");
        int n = sc.nextInt();
        Node head = null, tail = null;
        System.out.println("Enter digits (in reverse order):");
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
