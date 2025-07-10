public class Q1 
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
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);

        System.out.print("Head: ");
        revprint(head);
        System.out.println("NULL");
    }
    static void revprint(ListNode head)
    {
        if(head.next!=null)
            revprint(head.next);
        System.out.print(head.val+" -> ");
    }
}