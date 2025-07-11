import java.util.*;
class Day26Question1 
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

    public boolean swap(int k) 
    {
        int n = 0;
        Node temp = head;
        while (temp != null) 
        {
            n++;
            temp = temp.next;
        }

        k = k % n;
        if (k == 0) 
        k = n;

        if (k == n - k + 1) 
        {
             return false;
        }
        Node prev1 = null, s1 = head;
        for (int i = 1; i < k; i++) 
        {
            prev1 = s1;
            s1 = s1.next;
        }
        Node prev2 = null, s2 = head;
        for (int i = 1; i < n - k + 1; i++) 
        {
            prev2 = s2;
            s2 = s2.next;
        }
        if (prev1 != null) 
        {
            prev1.next = s2;
        } 
        else 
        {
            head = s2;
        }
        if (prev2 != null) 
        {
            prev2.next = s1;
        } 
        else 
        {
            head = s1;
        }

        Node tempNext = s1.next;
        s1.next = s2.next;
        s2.next = tempNext;
        return true;
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Day26Question1 list = new Day26Question1();

        System.out.print("Enter size of linkedlist: ");
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) 
        {
            System.out.print("Enter element: ");
            int data = sc.nextInt();
            list.insert(data);
        }

        System.out.print("Enter value of k to swap kth node from start and end: ");
        int k = sc.nextInt();
        boolean result = list.swap(k);
        System.out.println(result);
    }
}

