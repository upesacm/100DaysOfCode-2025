class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
    }
}
public class Q3
{
    public static void printList(ListNode node) 
    {
        while (node != null) {
            System.out.print(node.val+" ");
            node = node.next;
        }
        System.out.println();
    }
    public static void main(String[] args) 
    {
        ListNode head = new ListNode(49);
        head.next = new ListNode(10);
        head.next.next = new ListNode(30);
        
        printList(head);
    }
}
