public static ListNode deleteMiddle(ListNode head) {
    if (head == null || head.next == null) return null;

    ListNode slow = head, fast = head, prev = null;
    while (fast != null && fast.next != null) {
        prev = slow;
        slow = slow.next;
        fast = fast.next.next;
    }
    if (prev != null) {
        prev.next = slow.next;
    }

    return head;
}
