import java.util.*;
class Day24Question1 
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

    public void rev() 
    {
        Node prev = null;
        Node curr = head;
        Node next = null;

        while (curr != null) 
        {
            next = curr.next;   
            curr.next = prev;   
            prev = curr;        
            curr = next;       
        }
        head = prev;  
    }

    public void display() 
    {
        if (head == null) 
        {
            System.out.println("List is empty.");
            return;
        }

        Node temp = head;
        System.out.print("head: ");
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
        Day24Question1 list = new Day24Question1();

        System.out.print("Enter size of linkedlist: ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) 
        {
            System.out.print("Enter an element: ");
            int data = sc.nextInt();
            list.insert(data);
        }

        list.rev();
        System.out.println("Output:");
        list.display();
    }
}

