public class Q3
{
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) {
            this.val = val;
        }
    }
    public static void main(String args[])
    {
        ListNode head = new ListNode(1);
        head.next = new ListNode(3);
        head.next.next = new ListNode(4);
        
        int x=3;

        head = delNode(head, x);
        printList(head);
    }
    public static ListNode delNode(ListNode head, int x)
    {
        if (head == null) return null;

        if (x == 1) return head.next;

        ListNode cur = head;

        while(--x==0 && cur != null)
            cur = cur.next;

        if (cur == null || cur.next == null) return head;

        cur.next = cur.next.next;
        return head;
    }
    public static void printList(ListNode node) 
    {
        while (node != null) 
        {
            System.out.print(node.val+" -> ");
            node = node.next;
        }
        System.out.println("null");
    }
}