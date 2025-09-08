class Node {
    int data;
    Node left, right;
    Node(int val) {
        data = val;
        left = right = null;
    }
}

class ListNode {
    int data;
    ListNode next;
    ListNode(int val) {
        data = val;
        next = null;
    }
}

public class Q2 {
    static ListNode head = null, tail = null;

    public static void inorder(Node root) {
        if (root == null) return;
        inorder(root.left);
        ListNode node = new ListNode(root.data);
        if (head == null) head = tail = node;
        else {
            tail.next = node;
            tail = node;
        }
        inorder(root.right);
    }

    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.data);
            if (head.next != null) System.out.print(" → ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Node root = new Node(4);
        root.left = new Node(2);
        root.right = new Node(6);
        root.left.left = new Node(1);
        root.left.right = new Node(3);
        root.right.left = new Node(5);
        root.right.right = new Node(7);

        inorder(root);
        printList(head);
    }
}
