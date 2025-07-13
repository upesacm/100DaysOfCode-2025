import java.util.*;
class Day24Question2 
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

    // function to skip m nodes and delete n nodes
    public void skipDel(int m, int n) 
    {
        Node curr = head;
        while (curr != null) 
        {
            int i;
            for (i = 1; i < m && curr != null; i++) 
            {
                curr = curr.next;
            }

            if (curr == null) 
            {
                return;
            }
            Node temp = curr.next;
            for (i = 1; i <= n && temp != null; i++) 
            {
                temp = temp.next;
            }

            curr.next = temp;
            curr = temp;
        }
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
        Day24Question2 list = new Day24Question2();

        System.out.print("Enter size of linkedlist: ");
        int size = sc.nextInt();

        for (int i = 0; i < size; i++) 
        {
            int data = sc.nextInt();
            list.insert(data);
        }

        System.out.print("Enter number of nodes to skip: ");
        int m = sc.nextInt();
        System.out.print("Enter number of nodes to delete: ");
        int n = sc.nextInt();

        list.skipDel(m, n);
        System.out.println("Output:");
        list.display();
    }
}

