import java.util.*;
class Day22Question2 
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

    public void freq(int k) 
    {
        if (head == null) 
        {
            System.out.println("List is empty");
        } 
        else 
        {
            Node temp = head;
            int c = 0;

            while (temp != null) 
            {
                if (temp.data == k) 
                {
                    c++;
                }
                temp = temp.next;
            }
            System.out.println("Total occurrences of " + k + ": " + c);
        }
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Day22Question2 list = new Day22Question2();

        System.out.print("Enter size of linkedlist: ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) 
        {
            System.out.println("Enter an element: ");
            int data = sc.nextInt();
            list.insert(data);
        }

        System.out.print("Enter value of key: ");
        int key = sc.nextInt();

        list.freq(key);
    }
}
