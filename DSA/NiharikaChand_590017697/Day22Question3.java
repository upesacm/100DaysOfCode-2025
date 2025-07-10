import java.util.*;
class Day22Question3 
{
    static class Node 
    {
        int data;
        Node next;

        Node(int data) 
        {
            this.data = data;
            this.next = null;
        }
    }
    Node head;

    public void insert(int data) 
    {
        Node newNode = new Node(data);
        if (head == null) 
        {
            head = newNode;
            return;
        }
        Node temp = head;
        while (temp.next != null) 
        {
            temp = temp.next;
        }
        temp.next = newNode;
    }

    public void display()
    {
        if (head == null) {
            System.out.println("Linked list is empty.");
            return;
        }

        Node temp = head;
        System.out.print("Linked list elements: ");
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Day22Question3 list = new Day22Question3();

        System.out.print("Enter size of linkedlist: ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) 
        {
            System.out.println("Enter an element: ");
            int data = sc.nextInt();
            list.insert(data);
        }

        list.display();
    }
}