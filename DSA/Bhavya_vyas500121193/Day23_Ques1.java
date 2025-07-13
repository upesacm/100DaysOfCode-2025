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
