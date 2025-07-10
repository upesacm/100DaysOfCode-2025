public class Q3 {
    static class Node {
        int data;
        Node next;
        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    public static void main(String[] args) {
        Node num1 = new Node(4);
        num1.next = new Node(5);

        Node num2 = new Node(3);
        num2.next = new Node(4);
        num2.next.next = new Node(5);

        Node result = addLists(num1, num2);
        printList(result);  
    }

    public static Node addLists(Node l1, Node l2) {
        Node dummy = new Node(0);
        Node current = dummy;
        int carry = 0;

        while (l1 != null || l2 != null || carry > 0) {
            int sum = carry;

            if (l1 != null) {
                sum += l1.data;
                l1 = l1.next;
            }

            if (l2 != null) {
                sum += l2.data;
                l2 = l2.next;
            }

            carry = sum / 10;
            current.next = new Node(sum % 10);
            current = current.next;
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
