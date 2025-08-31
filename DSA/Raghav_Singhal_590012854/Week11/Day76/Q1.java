import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int value) {
        data = value;
        left = right = null;
    }
}

public class Q1 {
    public static int convertToSumTree(Node root) {
        if (root == null) return 0;
        int leftSum = convertToSumTree(root.left);
        int rightSum = convertToSumTree(root.right);
        int oldVal = root.data;
        root.data = leftSum + rightSum;
        return root.data + oldVal;
    }

    public static void printTree(Node root, String indent, boolean isLeft) {
        if (root == null) return;
        printTree(root.right, indent + (isLeft ? "│   " : "    "), false);
        System.out.println(indent + (isLeft ? "└── " : "┌── ") + root.data);
        printTree(root.left, indent + (isLeft ? "    " : "│   "), true);
    }

    public static void main(String[] args) {
        Node root = new Node(10);
        root.left = new Node(-2);
        root.right = new Node(6);
        root.left.left = new Node(8);
        root.left.right = new Node(-4);
        root.right.left = new Node(7);
        root.right.right = new Node(5);

        System.out.println("Original Tree:");
        printTree(root, "", false);

        convertToSumTree(root);

        System.out.println("\nSum Tree:");
        printTree(root, "", false);
    }
}
