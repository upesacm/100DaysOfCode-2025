class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

public class PrintLinkedList {
    public static void printList(ListNode head) {
        ListNode current = head;
        while (current != null) {
            System.out.print(current.val);
            if (current.next != null) System.out.print(" ");
            current = current.next;
        }
        System.out.println(); 
    }


    public static void main(String[] args) {
        ListNode head = new ListNode(49);
        head.next = new ListNode(10);
        head.next.next = new ListNode(30);

        printList(head);  
    }
}
