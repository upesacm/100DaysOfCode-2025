
class ListNode {

    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

class Q1 {

    public static int kfromend(ListNode head, int k) {
        if (head == null || k <= 0) {
            return -1;
        }

        ListNode first = head;
        ListNode second = head;

        for (int i = 0; i < k; i++) {
            if (first == null) {
                return -1;
            }
            first = first.next;
        }

        while (first != null) {
            first = first.next;
            second = second.next;
        }

        return second.val;
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

        int k = 2;
        int res = kfromend(head, k);

        System.out.println(res);
    }
}
