import java.util.TreeSet;
public class Q2 {
    static class Node {
        int data;
        Node next;
        Node(int data) {
            this.data = data;
        }
    }

    public static void main(String[] args) {
        Node l1 = createList(new int[]{9, 6, 4, 2, 3, 8});
        Node l2 = createList(new int[]{1, 2, 8, 6, 2});
        Node result = makeUnion(l1, l2);
        printList(result);  
    }

    public static Node makeUnion(Node head1, Node head2) {
        TreeSet<Integer> set = new TreeSet<>();
        while (head1 != null) {
            set.add(head1.data);
            head1 = head1.next;
        }
        while (head2 != null) {
            set.add(head2.data);
            head2 = head2.next;
        }

        Node dummy = new Node(0);
        Node curr = dummy;
        for (int val : set) {
            curr.next = new Node(val);
            curr = curr.next;
        }

        return dummy.next;
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
