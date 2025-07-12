import java.util.*;
class Day26Question3 
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

    public Node sort(Node head) 
    {
        Node zeroD = new Node(0);
        Node oneD = new Node(0);
        Node twoD = new Node(0);
        Node zero = zeroD, one = oneD, two = twoD;
        Node curr = head;

        while (curr != null) 
        {
            if (curr.data == 0) 
            {
                zero.next = curr;
                zero = zero.next;
            } 
            else if (curr.data == 1) 
            {
                one.next = curr;
                one = one.next;
            } 
            else 
            { 
                two.next = curr;
                two = two.next;
            }
            curr = curr.next;
        }

        zero.next = (oneD.next != null) ? oneD.next : twoD.next;
        one.next = twoD.next;
        two.next = null;
        return zeroD.next;
    }

    public void display(Node head) 
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
        System.out.println();
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Day26Question3 list = new Day26Question3();

        System.out.print("Enter size of linkedlist: ");
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) 
        {
            System.out.print("Enter element (0, 1, or 2): ");
            int data = sc.nextInt();
            list.insert(data);
        }

        list.head = list.sort(list.head);
        System.out.println("Output:");
        list.display(list.head);
    }
}