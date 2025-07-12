import java.util.*;
class Day26Question2 
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

    public Node union(Node head1, Node head2) 
    {
        Node cHead = null, cTail = null;
        Node temp = head1;
        while (temp != null) 
        {
            Node newNode = new Node(temp.data);
            if (cHead == null) 
            {
                cHead = newNode;
                cTail = newNode;
            } 
            else 
            {
                cTail.next = newNode;
                cTail = newNode;
            }
            temp = temp.next;
        }

        temp = head2;
        while (temp != null) 
        {
            Node newNode = new Node(temp.data);
            cTail.next = newNode;
            cTail = newNode;
            temp = temp.next;
        }

        cHead = sortList(cHead);
        cHead = remDup(cHead);
        return cHead;
    }

    private Node sortList(Node head) 
    {
        if (head == null || head.next == null)
            return head;

        Node i, j;
        for (i = head; i.next != null; i = i.next) 
        {
            for (j = i.next; j != null; j = j.next) 
            {
                if (i.data > j.data) 
                {
                    int temp = i.data;
                    i.data = j.data;
                    j.data = temp;
                }
            }
        }
        return head;
    }

    private Node remDup(Node head) 
    {
        Node current = head;
        while (current != null && current.next != null) 
        {
            if (current.data == current.next.data) 
            {
                current.next = current.next.next; 
            } 
            else 
            {
                current = current.next;
            }
        }
        return head;
    }

    public void display(Node head) 
    {
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
        Day26Question2 list1 = new Day26Question2();
        Day26Question2 list2 = new Day26Question2();
        System.out.print("Enter size of linkedlist1: ");
        int n1 = sc.nextInt();
        for (int i = 0; i < n1; i++) 
        {
            System.out.print("Enter element for L1: ");
            int data = sc.nextInt();
            list1.insert(data);
        }

        System.out.print("Enter size of linkedlist2: ");
        int n2 = sc.nextInt();
        for (int i = 0; i < n2; i++) 
        {
            System.out.print("Enter element for L2: ");
            int data = sc.nextInt();
            list2.insert(data);
        }

        Day26Question2 obj = new Day26Question2();
        Node unionHead = obj.union(list1.head, list2.head);

        System.out.println("Output:");
        obj.display(unionHead);
    }
}
