class ListNode {
    int val;
    ListNode next;
    ListNode(int val) {
        this.val = val;
    }
}
public class Q3
{
    public static void main(String[] args) 
    {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);
        head = rmMiddle(head);
        printList(head);
    }
    public static ListNode rmMiddle(ListNode head) 
    {
        if (head == null || head.next == null) return null;
        ListNode slow = head;
        ListNode fast = head;
        ListNode prev = null;
        while (fast != null && fast.next != null) 
        {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        if (prev != null) {
            prev.next = slow.next;
        }
        return head;
    }
    public static void printList(ListNode node) 
    {
        while (node != null) {
            System.out.print(node.val+" -> ");
            node = node.next;
        }
        System.out.println("null");
    }
}
