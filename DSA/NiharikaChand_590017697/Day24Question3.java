// 1-based indexing
import java.util.*;
class Day24Question3 
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

    public void delete(int pos) 
    {
        if (pos <= 0) 
        {
            System.out.println("Invalid");
            return;
        }
        if (head == null) 
        {
            System.out.println("List is empty");
            return;
        }
        if (pos == 1) 
        {
            head = head.next;
            return;
        }
        Node curr = head;
        for (int i = 1; i < pos - 1; i++) 
        {
            if (curr == null || curr.next == null) 
            {
                System.out.println("Invalid position");
                return;
            }
            curr = curr.next;
        }
        if (curr.next == null) 
        {
            System.out.println("Invalid position");
            return;
        }
        curr.next = curr.next.next;
    }

    public void display() 
    {
        if (head == null) 
        {
            System.out.println("Linkedlist is empty.");
            return;
        }
        Node temp = head;
        while (temp != null) 
        {
            System.out.print(temp.data + "->");
            temp = temp.next;
        }
        System.out.println("NULL");
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Day24Question3 list = new Day24Question3();

        System.out.print("Enter size of linkedlist: ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) 
        {
            int data = sc.nextInt();
            list.insert(data);
        }

        System.out.print("Enter position of node to delete: ");
        int pos = sc.nextInt();

        list.delete(pos);
        System.out.println("Output:");
        list.display();
    }
}