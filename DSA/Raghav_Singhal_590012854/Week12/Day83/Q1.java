import java.util.*;

class Node {
    int data;
    Node left, right;
    Node(int val) { data = val; left = right = null; }
}

public class Q1 {

    static class Pair {
        Node node;
        int hd;
        Pair(Node n, int h) { node = n; hd = h; }
    }

    public static List<List<Integer>> verticalOrder(Node root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;

        TreeMap<Integer, List<Integer>> map = new TreeMap<>();
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(root, 0));

        while (!q.isEmpty()) {
            Pair p = q.poll();
            map.putIfAbsent(p.hd, new ArrayList<>());
            map.get(p.hd).add(p.node.data);
            if (p.node.left != null) q.add(new Pair(p.node.left, p.hd - 1));
            if (p.node.right != null) q.add(new Pair(p.node.right, p.hd + 1));
        }

        result.addAll(map.values());
        return result;
    }

    public static void main(String[] args) {
        Node root1 = new Node(3);
        root1.left = new Node(9);
        root1.right = new Node(20);
        root1.right.left = new Node(15);
        root1.right.right = new Node(7);
        System.out.println(verticalOrder(root1));

        Node root2 = new Node(4);
        root2.left = new Node(2);
        root2.right = new Node(6);
        root2.left.left = new Node(1);
        root2.left.right = new Node(3);
        root2.right.left = new Node(5);
        root2.right.right = new Node(7);
        System.out.println(verticalOrder(root2));
    }
}
