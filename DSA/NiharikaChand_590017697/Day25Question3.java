import java.util.*;
class Day25Question3 
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

    private static Node rev(Node head) 
    {
        Node prev = null, curr = head, next = null;
        while (curr != null) 
        {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    private static Node add(Node head1, Node head2) 
    {
        head1 = rev(head1);
        head2 = rev(head2);

        Node dummy = new Node(0);
        Node tail = dummy;
        int carry = 0;
        while (head1 != null || head2 != null || carry != 0) 
        {
            int sum = carry;
            if (head1 != null) 
            {
                sum += head1.data;
                head1 = head1.next;
            }
            if (head2 != null) 
            {
                sum += head2.data;
                head2 = head2.next;
            }
            carry = sum / 10;
            tail.next = new Node(sum % 10);
            tail = tail.next;
        }

        Node result = rev(dummy.next);
        while (result != null && result.data == 0 && result.next != null) 
        {
            result = result.next;
        }
        return result;
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
        Day25Question3 num1 = new Day25Question3();
        Day25Question3 num2 = new Day25Question3();

        System.out.print("Enter size of linkedlist1: ");
        int n1 = sc.nextInt();
        System.out.println("First Linkedlist");
        for (int i = 0; i < n1; i++) 
        {
            System.out.print("Enter an element: ");
            int data = sc.nextInt();
            num1.insert(data);
        }

        System.out.print("Enter size of linkedlist2: ");
        int n2 = sc.nextInt();
        System.out.println("Second Linkedlist");
        for (int i = 0; i < n2; i++) 
        {
            System.out.print("Enter an element: ");
            int data = sc.nextInt();
            num2.insert(data);
        }

        Node result = add(num1.head, num2.head);
        System.out.println("Output: ");
        display(result);
    }
}
