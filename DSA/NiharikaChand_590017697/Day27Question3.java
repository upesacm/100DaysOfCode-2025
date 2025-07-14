import java.util.*;
class Day27Question3 
{
    static class Node 
    {
        int data;
        Node next;
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
    }

    public void remove(int k) 
    {
        if (head == null || k <= 0) 
        {
            System.out.println("Invalid");
            return;
        }
        if (k == 1) 
        {
            head = null;
            return;
        }
        Node temp = head;
        int count = 1;
        while (temp != null && temp.next != null) 
        {
            if (count == k - 1 && temp.next != null) 
            {
                temp.next = temp.next.next;
                count = 0; 
            }
            temp = temp.next;
            count++;
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
                System.out.print(" -> ");
            }
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Day27Question3 list = new Day27Question3();
        System.out.print("Enter size of linkedlist: ");
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) 
        {
            System.out.print("Enter an element: ");
            int data = sc.nextInt();
            list.insert(data);
        }
        System.out.print("Enter value of k: ");
        int k = sc.nextInt();

        list.remove(k);
        System.out.print("Output: ");
        list.display();
    }
}