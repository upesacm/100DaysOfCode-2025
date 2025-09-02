class Node {
    int data;
    Node left, right;

    Node(int value) {
        data = value;
        left = right = null;
    }
}

public class Q1 {
    public static boolean searchBST(Node root, int key) {
        if (root == null) return false;
        if (root.data == key) return true;
        if (key < root.data) return searchBST(root.left, key);
        return searchBST(root.right, key);
    }

    public static void inorderTraversal(Node root) {
        if (root == null) return;
        inorderTraversal(root.left);
        System.out.print(root.data + " ");
        inorderTraversal(root.right);
    }

    public static void main(String[] args) {
        Node root = new Node(8);
        root.left = new Node(3);
        root.right = new Node(10);
        root.left.left = new Node(1);
        root.left.right = new Node(6);
        root.left.right.left = new Node(4);
        root.left.right.right = new Node(7);
        root.right.right = new Node(14);
        root.right.right.left = new Node(13);

        System.out.print("Inorder Traversal of BST: ");
        inorderTraversal(root);

        int key = 7;
        if (searchBST(root, key))
            System.out.println("\nKey " + key + " found in BST");
        else
            System.out.println("\nKey " + key + " not found in BST");
    }
}
