// assume that we have a sorted linkedlist
import java.util.*;
class Day23Question2 
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

    public void removeDup()
    {
       Node curr = head;

        while (curr != null && curr.next != null) 
        {
            if (curr.data == curr.next.data) 
            {
                curr.next = curr.next.next;
            } 
            else 
            {
                curr = curr.next;
            }
        } 
    }

    public void display() 
    {
        Node temp = head;
        System.out.print("List after removing duplicates: ");
        while (temp != null) 
        {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

   public static void main(String args[]) 
    {
        Day23Question2 list = new Day23Question2();
        list.insert(2);
        list.insert(2);
        list.insert(4);
        list.insert(5);
        list.insert(2);

        list.removeDup();
        list.display();
    } 
}
