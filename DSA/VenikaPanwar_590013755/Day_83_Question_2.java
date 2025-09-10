import java.util.LinkedList;
import java.util.Queue;

public class Day_83_Question_2 {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    // Serialize BST to string (preorder)
    public static String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        serializeHelper(root, sb);
        return sb.length() > 0 ? sb.substring(0, sb.length() - 1) : "";
    }

    private static void serializeHelper(TreeNode root, StringBuilder sb) {
        if (root == null) return;
        sb.append(root.val).append(",");
        serializeHelper(root.left, sb);
        serializeHelper(root.right, sb);
    }

    // Deserialize string to BST
    public static TreeNode deserialize(String data) {
        if (data.isEmpty()) return null;
        String[] vals = data.split(",");
        Queue<Integer> queue = new LinkedList<>();
        for (String v : vals) queue.offer(Integer.parseInt(v));
        return deserializeHelper(queue, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    private static TreeNode deserializeHelper(Queue<Integer> queue, int min, int max) {
        if (queue.isEmpty()) return null;
        int val = queue.peek();
        if (val < min || val > max) return null;
        queue.poll();
        TreeNode root = new TreeNode(val);
        root.left = deserializeHelper(queue, min, val - 1);
        root.right = deserializeHelper(queue, val + 1, max);
        return root;
    }

    // Inorder traversal for demonstration
    public static void inorder(TreeNode root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.val + " ");
        inorder(root.right);
    }

    public static void main(String[] args) {
        // Example 1: Tree 2 / \ 1 3
        TreeNode root1 = new TreeNode(2);
        root1.left = new TreeNode(1);
        root1.right = new TreeNode(3);
        String ser1 = serialize(root1);
        System.out.println("Serialized: " + ser1); // Output: "2,1,3"
        TreeNode deser1 = deserialize(ser1);
        System.out.print("Deserialized Inorder: ");
        inorder(deser1); // Output: 1 2 3
        System.out.println();

        // Example 2: Tree 5 / \ 3 7
        TreeNode root2 = new TreeNode(5);
        root2.left = new TreeNode(3);
        root2.right = new TreeNode(7);
        String ser2 = serialize(root2);
        System.out.println("Serialized: " + ser2); // Output: "5,3,7"
        TreeNode deser2 = deserialize(ser2);
        System.out.print("Deserialized Inorder: ");
        inorder(deser2); // Output: 3 5 7
        System.out.println();
    }
}
