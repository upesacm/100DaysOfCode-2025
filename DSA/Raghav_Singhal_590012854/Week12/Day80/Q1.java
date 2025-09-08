class Node {
    int data;
    Node left, right;
    Node(int item) {
        data = item;
        left = right = null;
    }
}

public class Q1 {
    Node root;

    Node lowestCommonAncestor(Node root, Node p, Node q) {
        if (root == null) return null;
        if (p.data < root.data && q.data < root.data)
            return lowestCommonAncestor(root.left, p, q);
        else if (p.data > root.data && q.data > root.data)
            return lowestCommonAncestor(root.right, p, q);
        else
            return root;
    }

    public static void main(String[] args) {
        Q1 tree = new Q1();
        tree.root = new Node(6);
        tree.root.left = new Node(2);
        tree.root.right = new Node(8);
        tree.root.left.left = new Node(0);
        tree.root.left.right = new Node(4);
        tree.root.right.left = new Node(7);
        tree.root.right.right = new Node(9);
        tree.root.left.right.left = new Node(3);
        tree.root.left.right.right = new Node(5);

        Node p = tree.root.left;      
        Node q = tree.root.left.right;  

        Node lca = tree.lowestCommonAncestor(tree.root, p, q);
        System.out.println("LCA: " + lca.data);
    }
}
