import java.util.*;
class Day27Question2 
{
    static class Node 
    {
        int data;
        Node prev, next;
        Node(int data) 
        {
            this.data = data;
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
        newNode.prev = temp;
    }

    public void rev() 
    {
        Node temp = null;
        Node current = head;
        while (current != null) 
        {
            temp = current.prev;
            current.prev = current.next;
            current.next = temp;
            current = current.prev;
        }
        if (temp != null) 
        {
            head = temp.prev;
        }
    }

    public void display() 
    {
        Node temp = head;
        while (temp != null) 
        {
            System.out.print(temp.data);
            if (temp.next != null) 
            {
                System.out.print(" <--> ");
            }
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Day27Question2 list = new Day27Question2();
        System.out.print("Enter size of linkedlist: ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) 
        {
            System.out.print("Enter an element: ");
            int data = sc.nextInt();
            list.insert(data);
        }

        list.rev();
        System.out.print("Output: ");
        list.display();
    }
}