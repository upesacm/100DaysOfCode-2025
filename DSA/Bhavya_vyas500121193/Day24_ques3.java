public static ListNode deleteAtPosition(ListNode head, int x) {
    if (x <= 0) return head;
    if (x == 1) return head.next; 

    ListNode current = head;

    for (int i = 1; i < x - 1 && current != null; i++) {
        current = current.next;
    }

    if (current != null && current.next != null) {
        current.next = current.next.next;
    }

    return head;
}
