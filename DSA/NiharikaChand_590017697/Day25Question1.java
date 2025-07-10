import java.util.*;
class Day25Question1 
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

    public boolean palinCheck() 
    {
        if (head == null || head.next == null) 
        {
            return true; 
        }

        Node slow = head, fast = head;
        while (fast != null && fast.next != null) 
        {
            slow = slow.next;
            fast = fast.next.next;
        }

        Node sHalf = rev(slow);
        Node fHalf = head;
        Node secCopy = sHalf; 
        boolean result = true;

        while (sHalf != null) 
        {
            if (fHalf.data != sHalf.data) 
            {
                result = false;
                break;
            }
            fHalf = fHalf.next;
            sHalf = sHalf.next;
        }

        rev(secCopy);
        return result;
    }

    private Node rev(Node node) 
    {
        Node prev = null, curr = node, next = null;
        while (curr != null) 
        {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Day25Question1 list = new Day25Question1();

        System.out.print("Enter size of linkedlist: ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) 
        {
            System.out.print("Enter an element: ");
            int data = sc.nextInt();
            list.insert(data);
        }

        boolean result = list.palinCheck();
        System.out.println("Output: " + result);
    }
}
