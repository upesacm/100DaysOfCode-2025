import java.util.*;
class Day23Question3 
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

    public void deleteM() 
    {
        if (head == null) 
        {
            System.out.println("List not found");
            return;
        }
        if (head.next == null) 
        {
            head = null;
            return;
        }

        Node temp = head;
        Node prev = null;
        int count = 0;

        while (temp != null) 
        {
            count++;
            temp = temp.next;
        }

        int mid = count / 2;
        temp = head;

        for (int i = 0; i < mid; i++) 
        {
            prev = temp;
            temp = temp.next;
        }
        prev.next = temp.next;
    }

    public void display() 
    {
        if (head == null) 
        {
            System.out.println("Linked list is empty.");
            return;
        }

        Node temp = head;
        System.out.print("Linked list after deleting middle node: ");
        while (temp != null) 
        {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Day23Question3 list = new Day23Question3();
        System.out.print("Enter size of linkedlist: ");
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) 
        {
            System.out.println("Enter an element: ");
            int data = sc.nextInt();
            list.insert(data);
        }

        list.deleteM();
        list.display();
    }
}