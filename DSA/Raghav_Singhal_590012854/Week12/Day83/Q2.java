import java.util.*;

class Node {
    int data;
    Node left, right;
    Node(int val) { data = val; left = right = null; }
}

class Q2 {

    public static String serialize(Node root) {
        StringBuilder sb = new StringBuilder();
        preorder(root, sb);
        return sb.toString();
    }

    private static void preorder(Node root, StringBuilder sb) {
        if (root == null) return;
        sb.append(root.data).append(",");
        preorder(root.left, sb);
        preorder(root.right, sb);
    }

    public static Node deserialize(String data) {
        if (data.isEmpty()) return null;
        Queue<Integer> q = new LinkedList<>();
        for (String s : data.split(",")) q.add(Integer.parseInt(s));
        return build(q, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    private static Node build(Queue<Integer> q, int min, int max) {
        if (q.isEmpty()) return null;
        int val = q.peek();
        if (val < min || val > max) return null;
        q.poll();
        Node root = new Node(val);
        root.left = build(q, min, val);
        root.right = build(q, val, max);
        return root;
    }

    public static void inorder(Node root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    public static void main(String[] args) {
        Node root1 = new Node(2);
        root1.left = new Node(1);
        root1.right = new Node(3);

        String serialized1 = serialize(root1);
        System.out.println(serialized1);
        Node deserialized1 = deserialize(serialized1);
        inorder(deserialized1);
        System.out.println();

        Node root2 = new Node(5);
        root2.left = new Node(3);
        root2.right = new Node(7);

        String serialized2 = serialize(root2);
        System.out.println(serialized2);
        Node deserialized2 = deserialize(serialized2);
        inorder(deserialized2);
    }
}
