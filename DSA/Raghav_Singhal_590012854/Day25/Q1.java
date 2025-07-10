public class Q1
{
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) {
            this.val = val;
        }
    }
    static public ListNode head = new ListNode(1);

    public static void main(String args[])
    {
        head.next = new ListNode(2);
        head.next.next = new ListNode(1);
        head.next.next.next = new ListNode(1);
        head.next.next.next.next = new ListNode(2);
        head.next.next.next.next.next = new ListNode(1);
        System.out.println(isPalin(head));
    }
    static public boolean  value=true;
    public static boolean isPalin( ListNode cur)
    {
        if(cur.next!=null) {
            value = isPalin(cur.next);
        }
        if(head.next!=null && cur.val!=head.val && value)
        {
            value=false;
            return value;
        }
        head=head.next;
        return value;
    }
}