import java.util.*;

// Definition for a binary tree node
class BinaryTreeNode<T> {
    public T data;
    public BinaryTreeNode<T> left;
    public BinaryTreeNode<T> right;

    public BinaryTreeNode(T data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

public class Question1 {

    // Function to convert binary tree into sum tree
    public static int toSumTree(BinaryTreeNode<Integer> root) {
        if (root == null) return 0;

        // Store old value
        int oldVal = root.data;

        // Recursively convert left and right subtrees
        int leftSum = toSumTree(root.left);
        int rightSum = toSumTree(root.right);

        // Set current node’s data as sum of left + right subtree values
        root.data = leftSum + rightSum;

        // Return total sum including old value (for parent computation)
        return root.data + oldVal;
    }

    // Helper to build tree level order from user input
    public static BinaryTreeNode<Integer> buildTree(Scanner sc) {
        System.out.print("Enter root value (-1 for NULL): ");
        int val = sc.nextInt();
        if (val == -1) return null;

        BinaryTreeNode<Integer> root = new BinaryTreeNode<>(val);
        Queue<BinaryTreeNode<Integer>> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            BinaryTreeNode<Integer> curr = q.poll();

            System.out.print("Enter left child of " + curr.data + " (-1 for NULL): ");
            int leftVal = sc.nextInt();
            if (leftVal != -1) {
                curr.left = new BinaryTreeNode<>(leftVal);
                q.add(curr.left);
            }

            System.out.print("Enter right child of " + curr.data + " (-1 for NULL): ");
            int rightVal = sc.nextInt();
            if (rightVal != -1) {
                curr.right = new BinaryTreeNode<>(rightVal);
                q.add(curr.right);
            }
        }
        return root;
    }

    // Print inorder traversal
    public static void inorder(BinaryTreeNode<Integer> root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Build tree from user input
        BinaryTreeNode<Integer> root = buildTree(sc);

        System.out.println("\nInorder before conversion:");
        inorder(root);

        // Convert to Sum Tree
        toSumTree(root);

        System.out.println("\nInorder after conversion to Sum Tree:");
        inorder(root);
    }
}
