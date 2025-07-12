public class Q3 {
    static class Node {
        int data;
        Node next;
        Node(int data) {
            this.data = data;
        }
    }

    public static void main(String[] args) {
        Node head = createList(new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
        head = deleteEveryKthNode(head, 3);
        printList(head);
    }

    public static Node deleteEveryKthNode(Node head, int k) {
        if (k <= 1 || head == null) return null;

        Node curr = head;
        int count = 1;

        while (curr != null && curr.next != null) {
            if ((count + 1) % k == 0) {
                curr.next = curr.next.next;
            } else {
                curr = curr.next;
            }
            count++;
        }

        return head;
    }

    public static Node createList(int[] arr) {
        Node head = new Node(arr[0]);
        Node curr = head;
        for (int i = 1; i < arr.length; i++) {
            curr.next = new Node(arr[i]);
            curr = curr.next;
        }
        return head;
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
