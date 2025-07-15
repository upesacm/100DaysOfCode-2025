public class Q2
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
        ListNode head = new ListNode(9);
        head.next = new ListNode(1);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(5);
        head.next.next.next.next = new ListNode(9);
        head.next.next.next.next.next = new ListNode(4);
        head.next.next.next.next.next.next = new ListNode(10);
        head.next.next.next.next.next.next.next = new ListNode(1);

        int n=1,m=2;

        head=NafterM(head,n,m);
        printList(head);
    }
    public static ListNode NafterM(ListNode head, int n, int m)
    {
        ListNode cur = head;

        if(m<=0 && n>0) return head.next;

        while (m-- != 1 && cur != null ) 
        {
            cur = cur.next;
        }

        if (cur == null) return head;
        
        while (n-- > 0 && cur.next != null) 
        {
            cur.next = cur.next.next;
        }
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