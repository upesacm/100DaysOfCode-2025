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
    public static void leftSide(Node root) {
        if(root==null) return;
        System.out.println(root.data);
        if(root.left!=null) leftSide(root.left);
        else if(root.right!=null) leftSide(root.right);
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.right = new Node(6);
        root.left.left.left = new Node(7);
        root.right.right.left = new Node(8);

        leftSide(root);
    }
}
