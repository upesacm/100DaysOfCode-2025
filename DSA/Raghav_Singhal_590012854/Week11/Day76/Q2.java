import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int value) {
        data = value;
        left = right = null;
    }
}

public class Q2 {
    public static boolean printAncestors(Node root, int target) {
        if (root == null) return false;
        if (root.data == target) return true;
        if (printAncestors(root.left, target) || printAncestors(root.right, target)) {
            System.out.print(root.data + " ");
            return true;
        }
        return false;
    }

    public static void printTree(Node root, String indent, boolean isLeft) {
        if (root == null) return;
        printTree(root.right, indent + (isLeft ? "│   " : "    "), false);
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

        int target = 4;
        System.out.print("\nAncestors of " + target + ": ");
        printAncestors(root, target);
    }
}
