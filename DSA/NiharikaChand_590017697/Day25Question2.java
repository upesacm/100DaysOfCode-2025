import java.util.*;
class Day25Question2 
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

    public static Node find(Node head1, Node head2) 
    {
        Node result = new Node(0); 
        Node tail = result;

        Node ptr1 = head1;
        Node ptr2 = head2;

        while (ptr1 != null && ptr2 != null) 
        {
            if (ptr1.data == ptr2.data) 
            {
                tail.next = new Node(ptr1.data); 
                tail = tail.next;
                ptr1 = ptr1.next;
                ptr2 = ptr2.next;
            } 
            else if (ptr1.data < ptr2.data) 
            {
                ptr1 = ptr1.next;
            } 
            else 
            {
                ptr2 = ptr2.next;
            }
        }
        return result.next; 
    }

    public static void display(Node head) 
    {
        if (head == null) 
        {
            System.out.println("List is empty.");
            return;
        }
        Node temp = head;
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
        Day25Question2 list1 = new Day25Question2();
        Day25Question2 list2 = new Day25Question2();

        System.out.print("Enter size of linkedlist1: ");
        int n1 = sc.nextInt();
        System.out.println("First Linkedlist");
        for (int i = 0; i < n1; i++) 
        {
            System.out.print("Enter an element: ");
            int data = sc.nextInt();
            list1.insert(data);
        }

        System.out.print("Enter size of linkedlist2: ");
        int n2 = sc.nextInt();
        System.out.println("Second Linkedlist: ");
        for (int i = 0; i < n2; i++) 
        {
            System.out.print("Enter an element: ");
            int data = sc.nextInt();
            list2.insert(data);
        }

        Node intersection = find(list1.head, list2.head);
        System.out.println("Output: ");
        display(intersection);
    }
}
