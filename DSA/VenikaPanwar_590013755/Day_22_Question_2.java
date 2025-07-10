import java.util.*;

public class Day_22_Question_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node head = null, tail = null;

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        System.out.println("Enter " + n + " integers:");
        for (int i = 0; i < n; i++) {
            Node newNode = new Node(sc.nextInt());
            if (head == null) {
                head = newNode;
                tail = newNode;
            } else {
                tail.next = newNode;
                tail = newNode;
            }
        }

        System.out.print("Enter key to search: ");
        int key = sc.nextInt();
        int count = 0;
        Node temp = head;

        while (temp != null) {
            if (temp.data == key) count++;
            temp = temp.next;
        }

        System.out.println("Frequency of " + key + ": " + count);
    }
}
