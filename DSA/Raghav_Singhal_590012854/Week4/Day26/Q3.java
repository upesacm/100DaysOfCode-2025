public class Q3 {
    static class node{
        int val;
        node next;
        node(int val)
        {
            this.val=val;
        }
    }
    public static void main(String[] args) {
        node head=new node(1);
        head.next=new node(2);
        head.next.next=new node(2);
        head.next.next.next=new node(1);
        head.next.next.next.next=new node(2);
        head.next.next.next.next.next=new node(0);
        head.next.next.next.next.next.next=new node(2);
        head.next.next.next.next.next.next.next=new node(2);
        
        node newHead=dutch(head);
        printList(newHead);
    }
    public static node dutch(node head)
    {
        if (head == null || head.next == null) return head;

        node zerol = new node(-1), onel = new node(-1), twol = new node(-1);
        node zero = zerol, one = onel, two = twol;

        node cur = head;

        while (cur != null) 
        {
            if (cur.val == 0) 
            {
                zero.next = cur;
                zero = zero.next;
            } else if (cur.val == 1) {
                one.next = cur;
                one = one.next;
            } else {
                two.next = cur;
                two = two.next;
            }
            cur = cur.next;
        }

        zero.next = onel.next != null ? onel.next : twol.next;
        one.next = twol.next;
        two.next = null;
        
        return zerol.next;
    }

    public static void printList(node node) 
    {
        while (node != null) 
        {
            System.out.print(node.val+" -> ");
            node = node.next;
        }
        System.out.println("null");
    }
}
