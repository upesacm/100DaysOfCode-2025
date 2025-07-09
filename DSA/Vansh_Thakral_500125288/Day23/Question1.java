class ListNode {
    int val;
    ListNode next;
    ListNode(int val) { this.val = val; }
}

public class Question1 {
    public static int findKthFromEnd(ListNode head, int k) {
        ListNode fast = head, slow = head;

        for (int i = 0; i < k; i++) {
            if (fast == null) return -1; 
            fast = fast.next;
        }

        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }

        return (slow != null) ? slow.val : -1;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);
        head.next.next.next.next.next = new ListNode(6);
        head.next.next.next.next.next.next = new ListNode(7);
        head.next.next.next.next.next.next.next = new ListNode(8);
        head.next.next.next.next.next.next.next.next = new ListNode(9);

        System.out.println(findKthFromEnd(head, 2));  
    }
}
