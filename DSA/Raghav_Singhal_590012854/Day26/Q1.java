public class Q1 {
    static class node{
        int val;
        node next;
        node(int val)
        {
            this.val=val;
        }
    }
    public static node head;
    static int k=1,let=k,temp=k;
    public static node cur;
    public static void main(String[] args) {
        head=new node(1);
        head.next=new node(2);
        head.next.next=new node(3);
        head.next.next.next=new node(4);
        cur = head;
        swap(head);
        if(let==1)
        printList(cur);
        else 
        printList(head);
    }
    public static node swap(node head)
    {
        if(k==0) return null;
        if(temp>2)
        {
            temp--;
            cur=cur.next;
        }
        if(head.next!=null)
            swap(head.next);
        if(temp--==0 && let==1)
        {
            node dummy=cur;

            cur=head.next;
            cur.next=dummy.next;


            head.next=dummy;
            head.next.next=null;

            k=-5;
            head=cur;
            return head;
        }
        else if(--k==-1)
        {
            node dummy=head.next;
            head.next=cur.next;
            cur.next=dummy;
            
            head=head.next;
            cur=cur.next;

            dummy=head.next;
            head.next=cur.next;
            cur.next=dummy;
            cur=head;
        }
        return cur;
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
