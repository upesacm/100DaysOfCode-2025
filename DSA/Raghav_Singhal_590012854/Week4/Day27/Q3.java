public class Q3 {
    static class node {
        int val;
        node next;
        node(int val) { this.val = val; }
    }

    public static node deleteKthnode(node head, int k) {
        if (k <= 0 || head == null) return head;
        if (k == 1) return null;

        node cur = head;
        int count = 1;

        while (cur != null && cur.next != null) {
            if ((count + 1) % k == 0) {
                cur.next = cur.next.next;
                count++;
            } else {
                cur = cur.next;
                count++;
            }
        }

        return head;
    }

    public static void printList(node head) {
        while (head != null) {
            System.out.print(head.val + (head.next != null ? " -> " : ""));
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        node head = new node(1);
        head.next = new node(2);
        head.next.next = new node(3);
        head.next.next.next = new node(4);
        head.next.next.next.next = new node(5);
        head.next.next.next.next.next = new node(6);
        head.next.next.next.next.next.next = new node(7);
        head.next.next.next.next.next.next.next = new node(8);

        head = deleteKthnode(head, 2);
        printList(head);
    }
}
