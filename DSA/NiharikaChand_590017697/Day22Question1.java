import java.util.*;
class Day22Question1 
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

    public void findMid() 
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
                c++;
                temp = temp.next;
            }
            int midPos = c / 2;
            temp = head; 
            int i;
            for (i = 0; i < midPos; i++)
            {
                temp = temp.next;
            }
            System.out.println("Middle element: " + temp.data);
        }
    }

    public static void main(String args[]) 
    {
        Day22Question1 list = new Day22Question1();
        list.insert(2);
        list.insert(4);
        list.insert(6);
        list.insert(7);
        list.insert(5);
        list.insert(1);

        list.findMid();
    }
}