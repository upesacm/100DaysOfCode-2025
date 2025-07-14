public class Q2 {
    static class Node {
        int data;
        Node next;
        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }
    public static void main(String[] args) {
        Node l1 = new Node(1);
        l1.next = new Node(2);
        l1.next.next = new Node(3);
        l1.next.next.next = new Node(4);
        l1.next.next.next.next = new Node(6);

        Node l2 = new Node(2);
        l2.next = new Node(4);
        l2.next.next = new Node(6);
        l2.next.next.next = new Node(8);

        Node result = getIntersection(l1, l2);
        printList(result); 
    }

    public static Node getIntersection(Node l1, Node l2) {
        Node dummy = new Node(0);
        Node tail = dummy;

        while (l1 != null && l2 != null) {
            if (l1.data == l2.data) {
                tail.next = new Node(l1.data);
                tail = tail.next;
                l1 = l1.next;
                l2 = l2.next;
            } else if (l1.data < l2.data) {
                l1 = l1.next;
            } else {
                l2 = l2.next;
            }
        }

        return dummy.next;
    }

    public static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data);
            if (head.next != null) System.out.print(" -> ");
            head = head.next;
        }
        System.out.println();
    }
}
