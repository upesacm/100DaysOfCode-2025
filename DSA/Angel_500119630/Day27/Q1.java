public class Q1 {
    static class Node {
        int data;
        Node prev, next;
        Node(int data) {
            this.data = data;
        }
    }

    public static void main(String[] args) {
        Node head = createDLL(new int[]{1, 5, 2, 9});
        head = deleteNodeAtPosition(head, 1);
        printDLL(head); 
    }

    public static Node deleteNodeAtPosition(Node head, int pos) {
        if (head == null) return null;

        if (pos == 1) {
            head = head.next;
            if (head != null) head.prev = null;
            return head;
        }

        Node curr = head;
        for (int i = 1; curr != null && i < pos; i++) {
            curr = curr.next;
        }

        if (curr == null) return head;

        if (curr.prev != null) curr.prev.next = curr.next;
        if (curr.next != null) curr.next.prev = curr.prev;

        return head;
    }

    public static Node createDLL(int[] arr) {
        Node head = new Node(arr[0]);
        Node curr = head;
        for (int i = 1; i < arr.length; i++) {
            Node temp = new Node(arr[i]);
            curr.next = temp;
            temp.prev = curr;
            curr = temp;
        }
        return head;
    }

    public static void printDLL(Node head) {
        while (head != null) {
            System.out.print(head.data);
            if (head.next != null) System.out.print(" <--> ");
            head = head.next;
        }
        System.out.println();
    }
}
