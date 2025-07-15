public class Q3 {
    static class ListNode 
    {
        int val;
        ListNode next;
        ListNode(int val) 
        {
            this.val = val;
        }
    }
    static ListNode head1;
    static ListNode head2;


    public static void main(String[] args) 
    {
        head1 = new ListNode(4);
        head1.next = new ListNode(5);

        head2 = new ListNode(3);
        head2.next = new ListNode(4);
        head2.next.next = new ListNode(5);

        equalize();
        printList(add(head1, head2));
    }
    public static void equalize()
    {
        int c1=0,c2=0;
        ListNode temp1=head1,temp2=head2;
        while(temp1.next!=null)
        {
            c1++;
            temp1=temp1.next;
        }
        while(temp2.next!=null)
        {
            c2++;
            temp2=temp2.next;
        }
        if(c1>c2)
        {
            while(c1!=c2)
            {
                ListNode temp=head2;
                head2=new ListNode(0);
                head2.next=temp;
                c2++;
            }
        }
        else if(c2>c1)
        {
            while(c1!=c2)
            {
                ListNode temp=head1;
                head1=new ListNode(0);
                head1.next=temp;
                c1++;
            }
        }
    }
    public static ListNode add(ListNode head1, ListNode head2) {
        ListNode temp = new ListNode(-1);
        ListNode current = temp;
        ListNode prev = temp;
        int carry = 0;

        while (head1 != null || head2 != null || carry != 0) {
            if(carry!=0)
            prev.val+=carry;

            int v1 = (head1 != null) ? head1.val : 0;
            int v2 = (head2 != null) ? head2.val : 0;

            int sum = v1 + v2;
            carry = sum / 10;
            
            current.next = new ListNode(sum % 10);
            prev=current;
            current = current.next;
            if (head1 != null) head1 = head1.next;
            if (head2 != null) head2 = head2.next;
        }

        return temp.next;
    }
    public static void printList(ListNode node) 
    {
        while (node.next != null) 
        {
            System.out.print(node.val+" -> ");
            node = node.next;
        }
        System.out.println("null");
    }
}
