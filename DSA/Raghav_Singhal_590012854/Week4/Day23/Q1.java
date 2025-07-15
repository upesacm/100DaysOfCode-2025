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
        head.next.next.next.next = new ListNode(5);
        head.next.next.next.next.next = new ListNode(6);
        head.next.next.next.next.next.next = new ListNode(7);
        head.next.next.next.next.next.next.next = new ListNode(8);
        head.next.next.next.next.next.next.next.next = new ListNode(9);

        int k=2;
        ListNode kth=kthElement(head,k);
        if(kth==null)
        System.out.println("-1");
        else
        System.out.println(kth.val);
    }
    static int count=0;
    static ListNode cur=null;
    static ListNode kthElement(ListNode head,int k)
    {
        if(head.next!=null)
            kthElement(head.next, k);
        count++;
        if(k==count)
            cur= head;
        return cur;
    }
}