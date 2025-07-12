public class Q2 {
    static class Node {
        int data;
        Node prev, next;
        Node(int data) {
            this.data = data;
        }
    }

    public static void main(String[] args) {
        Node head = createDLL(new int[]{75, 122, 59, 196});
        head = reverseDLL(head);
        printDLL(head); 
    }

    public static Node reverseDLL(Node head) {
        Node curr = head;
        Node temp = null;

        while (curr != null) {
            temp = curr.prev;
            curr.prev = curr.next;
            curr.next = temp;
            curr = curr.prev;
        }

        if (temp != null) {
            head = temp.prev;
        }

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
