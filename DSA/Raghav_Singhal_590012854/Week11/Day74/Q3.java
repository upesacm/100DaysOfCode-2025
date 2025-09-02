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
    public static void printPaths(Node root) {
        List<Integer> path = new ArrayList<>();
        backtrack(root, path);
    }

    private static void backtrack(Node node, List<Integer> path) {
        if (node == null) return;
        path.add(node.data);
        if (node.left == null && node.right == null) {
            for (int i = 0; i < path.size(); i++) {
                System.out.print(path.get(i));
                if (i < path.size() - 1) System.out.print(" -> ");
            }
            System.out.println();
        } else {
            backtrack(node.left, path);
            backtrack(node.right, path);
        }
        path.remove(path.size() - 1);
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.right = new Node(6);
        root.right.right.left = new Node(7);

        printPaths(root);
    }
}
