
import java.util.*;

class Question1 {

    static class Node {

        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    Node head; // instance variable

    // Method to find Kth node from the end
    public int kthNodeFromEnd(int k) {
        Node slow = head;
        Node fast = head;

        for (int i = 0; i < k; i++) {
            if (fast == null) {
                return -1;
            }
            fast = fast.next;
        }

        while (fast != null) {
            slow = slow.next;
            fast = fast.next;
        }

        return slow.data;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Question1 list = new Question1(); // create object

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        System.out.print("Enter value for node 1: ");
        int value = sc.nextInt();
        list.head = new Node(value); //assign to instance variable
        Node current = list.head;

        for (int i = 2; i <= n; i++) {
            System.out.print("Enter value for node " + i + ": ");
            value = sc.nextInt();
            current.next = new Node(value);
            current = current.next;
        }

        System.out.print("Enter value of k: ");
        int k = sc.nextInt();

        int result = list.kthNodeFromEnd(k);
        System.out.println(result);
    }
}
