public class Q1
{
    static class node {
        int val;
        node prev, next;
        node(int val) { this.val = val; }
    }

    public static node deleteNode(node head, int x) 
    {
        if (head == null) return null;

        if (x == 1) 
        {
            head = head.next;
            if (head != null) head.prev = null;
            return head;
        }

        node cur = head;
        for (int i = 1; cur != null && i < x; i++) 
        {
            cur = cur.next;
        }

        if (cur == null) return head;

        if (cur.prev != null) cur.prev.next = cur.next;
        if (cur.next != null) cur.next.prev = cur.prev;

        return head;
    }

    public static void printList(node head) {
        while (head != null) {
            System.out.print(head.val + (head.next != null ? " <-> " : ""));
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) 
    {
        node head = new node(1);
        head.next = new node(3);
        head.next.prev = head;
        head.next.next = new node(4);
        head.next.next.prev = head.next;

        head = deleteNode(head, 3);
        printList(head);
    }
}