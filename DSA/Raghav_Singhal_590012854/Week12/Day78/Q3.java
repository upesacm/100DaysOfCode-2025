class Node {
    int data;
    Node left, right;

    Node(int value) {
        data = value;
        left = right = null;
    }
}

public class Q3 {

    public static Node insertBst(Node root, int e) {
        if (root == null) return new Node(e);
        if (e < root.data) root.left = insertBst(root.left, e);
        else if (e > root.data) root.right = insertBst(root.right, e);
        return root;
    }

    public static int findMin(Node root) {
        if (root == null) return -1;
        while (root.left != null) root = root.left;
        return root.data;
    }

    public static int findMax(Node root) {
        if (root == null) return -1;
        while (root.right != null) root = root.right;
        return root.data;
    }

    public static void inorderTraversal(Node root) {
        if (root == null) return;
        inorderTraversal(root.left);
        System.out.print(root.data + " ");
        inorderTraversal(root.right);
    }

    public static void main(String[] args) {
        Node root = null;
        root = insertBst(root, 8);
        root = insertBst(root, 3);
        root = insertBst(root, 10);
        root = insertBst(root, 1);
        root = insertBst(root, 6);
        root = insertBst(root, 14);

        System.out.print("Inorder Traversal: ");
        inorderTraversal(root);
        System.out.println();

        System.out.println("Min = " + findMin(root) + ", Max = " + findMax(root));
    }
}
