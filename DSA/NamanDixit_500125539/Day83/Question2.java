// Filename: Question1.java

import java.util.*;

// Definition for a binary tree node
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}

class Codec {
    // Encodes a tree to a single string
    public String serialize(TreeNode root) {
        if (root == null) return "";
        Queue<TreeNode> q = new LinkedList<>();
        StringBuilder res = new StringBuilder();
        q.add(root);

        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            if (node == null) {
                res.append("n ");
                continue;
            }
            res.append(node.val + " ");
            q.add(node.left);
            q.add(node.right);
        }
        return res.toString().trim();
    }

    // Decodes your encoded data to tree
    public TreeNode deserialize(String data) {
        if (data.equals("")) return null;
        String[] values = data.split(" ");
        TreeNode root = new TreeNode(Integer.parseInt(values[0]));
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        for (int i = 1; i < values.length; i++) {
            TreeNode parent = q.poll();

            if (!values[i].equals("n")) {
                TreeNode left = new TreeNode(Integer.parseInt(values[i]));
                parent.left = left;
                q.add(left);
            }

            if (++i < values.length && !values[i].equals("n")) {
                TreeNode right = new TreeNode(Integer.parseInt(values[i]));
                parent.right = right;
                q.add(right);
            }
        }
        return root;
    }
}

public class Question2 {
    // Helper function to take tree input (level order)
    public static TreeNode buildTree(Scanner sc) {
        System.out.print("Enter root value (-1 for null): ");
        int rootVal = sc.nextInt();
        if (rootVal == -1) return null;

        TreeNode root = new TreeNode(rootVal);
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            TreeNode current = queue.poll();

            System.out.print("Enter left child of " + current.val + " (-1 for null): ");
            int leftVal = sc.nextInt();
            if (leftVal != -1) {
                current.left = new TreeNode(leftVal);
                queue.add(current.left);
            }

            System.out.print("Enter right child of " + current.val + " (-1 for null): ");
            int rightVal = sc.nextInt();
            if (rightVal != -1) {
                current.right = new TreeNode(rightVal);
                queue.add(current.right);
            }
        }
        return root;
    }

    // Simple preorder traversal to check correctness
    public static void preorder(TreeNode root) {
        if (root == null) return;
        System.out.print(root.val + " ");
        preorder(root.left);
        preorder(root.right);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Build tree from user input
        TreeNode root = buildTree(sc);

        Codec codec = new Codec();

        // Serialize
        String serialized = codec.serialize(root);
        System.out.println("Serialized Tree: " + serialized);

        // Deserialize
        TreeNode deserializedRoot = codec.deserialize(serialized);
        System.out.print("Preorder of Deserialized Tree: ");
        preorder(deserializedRoot);
        System.out.println();

        sc.close();
    }
}
