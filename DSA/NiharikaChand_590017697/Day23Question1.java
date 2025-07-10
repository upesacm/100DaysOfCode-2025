import java.util.*;
class Day23Question1 
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

    public int find(int k) 
    {
        int len = 0;
        Node temp = head;

        while (temp != null) 
        {
            len++;
            temp = temp.next;
        }
        if (k > len || k <= 0) 
        {
            return -1; 
        }
        int posStart = len - k;
        temp = head;
        for (int i = 0; i < posStart; i++) 
        {
            temp = temp.next;
        }
        return temp.data;
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Day23Question1 list = new Day23Question1();
        System.out.print("Enter linkedlist size: ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) 
        {
            System.out.println("Enter an element: ");
            int data = sc.nextInt();
            list.insert(data);
        }

        System.out.print("Enter value of k: ");
        int k = sc.nextInt();
        int result = list.find(k);

        System.out.println("Output: " + result);
    }
}