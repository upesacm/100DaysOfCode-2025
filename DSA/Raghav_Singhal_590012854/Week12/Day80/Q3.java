class Node {
    int data;
    Node left, right;
    Node(int val) {
        data = val;
        left = right = null;
    }
}

public class Q3 {
    static int count = 0;

    public static Node insert(Node root, int val) {
        if (root == null) return new Node(val);
        if (val < root.data) root.left = insert(root.left, val);
        else if (val > root.data) root.right = insert(root.right, val);
        return root;
    }

    public static int kthSmallest(Node root, int k) {
        if (root == null) return -1;
        int left = kthSmallest(root.left, k);
        if (left != -1) return left;
        count++;
        if (count == k) return root.data;
        return kthSmallest(root.right, k);
    }

    public static void main(String[] args) {
        Node root = null;
        root = insert(root, 5);
        root = insert(root, 3);
        root = insert(root, 6);
        root = insert(root, 2);
        root = insert(root, 4);
        root = insert(root, 1);

        int k = 3;
        System.out.println(kthSmallest(root, k));
    }
}
