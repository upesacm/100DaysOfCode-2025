import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int value) {
        data = value;
        left = right = null;
    }
}

public class Q3 {
    public static int countNodesAtLevel(Node root, int level) {
        if (root == null) return 0;
        if (level == 1) return 1;
        return countNodesAtLevel(root.left, level - 1) + countNodesAtLevel(root.right, level - 1);
    }

    public static void printTree(Node root, String indent, boolean isLeft) {
        if (root == null) return;
        printTree(root.right, indent + (isLeft ? "   " : "    "), false);
        System.out.println(indent + (isLeft ? "└── " : "┌── ") + root.data);
        printTree(root.left, indent + (isLeft ? "    " : "│   "), true);
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);

        System.out.println("Binary Tree:");
        printTree(root, "", false);

        int level = 2;
        int count = countNodesAtLevel(root, level);

        System.out.println("\nNumber of nodes at level " + level + ": " + count);
    }
}