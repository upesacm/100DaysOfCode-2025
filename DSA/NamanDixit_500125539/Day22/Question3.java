import java.util.Scanner;

public class Question3 {
    // Node class
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // Method to print the linked list
    public void printList(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println(); // for newline after printing
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

        Question3 list=new Question3();
        list.printList(head);
    
}
}
