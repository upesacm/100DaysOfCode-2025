import java.util.Scanner;

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {

    // Function to delete every k-th node
    public Node deleteKthNode(Node head, int k) {
        if (head == null || k <= 0)
            return head;

        // If k is 1, delete entire list
        if (k == 1) {
            head = null;
            return null;
        }

        Node ptr = head;
        Node prev = null;
        int count = 0;

        while (ptr != null) {
            count++;

            if (count == k) {
                // delete ptr node
                if (prev != null) {
                    prev.next = ptr.next;
                }
                count = 0;
                ptr = prev.next;
            } else {
                prev = ptr;
                ptr = ptr.next;
            }
        }

        return head;
    }

    // Function to insert node at end
    public Node insertAtEnd(Node head, int data) {
        Node newNode = new Node(data);
        if (head == null)
            return newNode;

        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }

        temp.next = newNode;
        return head;
    }

    // Function to display the list
    public void printList(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}

public class Question3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList list = new LinkedList();
        Node head = null;

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        System.out.println("Enter elements:");
        for (int i = 0; i < n; i++) {
            head = list.insertAtEnd(head, sc.nextInt());
        }

        System.out.print("Enter value of k: ");
        int k = sc.nextInt();
        list.printList(head);

        head = list.deleteKthNode(head, k);

        list.printList(head);
    }
}
