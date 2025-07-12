public class Q1 {
    static class Node {
        int data;
        Node next;
        Node(int data) {
            this.data = data;
        }
    }

    public static void main(String[] args) {
        Node head = createList(new int[]{1, 2, 3, 4});
        head = swapKthNodes(head, 1);
        printList(head);
    }

    public static Node swapKthNodes(Node head, int k) {
        int n = 0;
        Node temp = head;
        while (temp != null) {
            n++;
            temp = temp.next;
        }

        if (k > n || 2 * k - 1 == n) return head;

        Node firstPrev = null, first = head;
        for (int i = 1; i < k; i++) {
            firstPrev = first;
            first = first.next;
        }

        Node secondPrev = null, second = head;
        for (int i = 1; i < n - k + 1; i++) {
            secondPrev = second;
            second = second.next;
        }

        if (firstPrev != null) firstPrev.next = second;
        if (secondPrev != null) secondPrev.next = first;

        Node tempNode = first.next;
        first.next = second.next;
        second.next = tempNode;

        return k == 1 ? second : head;
    }

    public static Node createList(int[] arr) {
        Node head = new Node(arr[0]), temp = head;
        for (int i = 1; i < arr.length; i++) {
            temp.next = new Node(arr[i]);
            temp = temp.next;
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
