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
        ListNode head1 = new ListNode(1);
        head1.next = new ListNode(2);
        head1.next.next = new ListNode(3);
        head1.next.next.next = new ListNode(4);
        head1.next.next.next.next = new ListNode(6);

        ListNode head2 = new ListNode(2);
        head2.next = new ListNode(4);
        head2.next.next = new ListNode(6);
        head2.next.next.next = new ListNode(8);
        
        ListNode newHead=common(head1,head2);
        printList(newHead);
    }
    public static ListNode common( ListNode head1,ListNode head2)
    {
        ListNode newHead = new ListNode(-1);
        ListNode tail = newHead;
        while(head1 != null && head2 != null)
        {
            if(head1.val == head2.val)
            {
                tail.next = new ListNode(head1.val);
                tail = tail.next;
                head1 = head1.next;
                head2 = head2.next;
            }
            else if(head1.val > head2.val)
                head2 = head2.next;
            else
                head1 = head1.next;
        }
        return newHead.next;
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