public class Q2 {
    static class node {
        int val;
        node prev, next;
        node(int val) { this.val = val; }
    }

    public static node reverse(node head) 
    {
        node cur = head, temp = null;

        while (cur != null) {
            temp = cur.prev;
            cur.prev = cur.next;
            cur.next = temp;
            cur = cur.prev;
        }

        if (temp != null) head = temp.prev;
        return head;
    }

    public static void printList(node head) 
    {
        while (head != null) {
            System.out.print(head.val + (head.next != null ? " <-> " : ""));
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) 
    {
        node head = new node(3);
        head.next = new node(4);
        head.next.prev = head;
        head.next.next = new node(5);
        head.next.next.prev = head.next;

        head = reverse(head);
        printList(head);
    }
}
