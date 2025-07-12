import java.util.*;
class Day27Question1 
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

    public void delete(int x) 
    {
        if (head == null || x <= 0) 
        {
            System.out.println("Invalid position");
            return;
        }

        Node temp = head;
        int c = 1;

        while (temp != null && c < x) 
        {
            temp = temp.next;
            c++;
        }

        
        if (temp == null) 
        {
            System.out.println("Position out of bounds");
            return;
        }

        if (temp == head) 
        {
            head = temp.next;
            if (head != null) 
            {
                head.prev = null;
            }
        }
        else 
        {
            if (temp.prev != null) 
            {
                temp.prev.next = temp.next;
            }
            if (temp.next != null) 
            {
                temp.next.prev = temp.prev;
            }
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
        Day27Question1 list= new Day27Question1();
        System.out.print("Enter size of linkedlist: ");
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) 
        {
            System.out.print("Enter an element: ");
            int data = sc.nextInt();
            list.insert(data);
        }

        System.out.println("Enter position to delete node from: ");
        int x = sc.nextInt();
        list.delete(x);
        System.out.println("Output: ");
        list.display();
    }
}