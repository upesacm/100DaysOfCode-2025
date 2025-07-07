import java.util.Scanner;


public class Question2 {

    
    // Node class
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // Method to count occurrences of a value
    public int getCountOfValue(Node node, int val) {
        if (node == null) {
            return -1;
        }

        int count = 0;
        while (node != null) {
            if (node.data == val) {
                count++;
            }
            node = node.next;
        }

        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();
        System.out.print("Enter value for node 1: ");

int value = sc.nextInt();
        Node head = new Node(value);
        Node current = head;


    for (int i = 2; i <= n; i++) {
            System.out.print("Enter value for node " + i + ": ");
            value = sc.nextInt();
            current.next = new Node(value);
            current = current.next;

        }

        System.out.print("Enter value to count: ");
        int target = sc.nextInt();
        Question2 list=new Question2();

        int result = list.getCountOfValue(head, target);

        if (result == -1) {
            System.out.println("Linked list is empty.");
        } else {
            System.out.println("Value " + target + " occurred " + result + " times.");
        }
    
}
}
