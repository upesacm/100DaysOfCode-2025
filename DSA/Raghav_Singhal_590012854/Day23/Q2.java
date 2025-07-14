public class Q2 {
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) {
            this.val = val;
        }
    }

    public static void main(String args[]) {
        ListNode head = new ListNode(2);
        head.next = new ListNode(2);
        head.next.next = new ListNode(4);
        head.next.next.next = new ListNode(5);
        head = rmDups(head);
        printList(head);
    }

    public static ListNode rmDups(ListNode head) {
        if (head == null) return null;

        ListNode temp1 = head;
        while (temp1 != null) {
            ListNode temp2 = temp1;
            while (temp2.next != null)
                if (temp1.val == temp2.next.val)
                    temp2.next = temp2.next.next;
                else
                    temp2 = temp2.next;
            temp1 = temp1.next;
        }
        return head;
    }

    public static void printList(ListNode node) {
        while (node != null) {
            System.out.print(node.val + " -> ");
            node = node.next;
        }
        System.out.println("null");
    }
}
