import java.util.*;

// Definition of TreeNode
class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int val) {
        this.val = val;
        left = right = null;
    }
}

public class Question2 {

    // Function to insert a value into BST
    public static TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) {
            return new TreeNode(val);
        }
        TreeNode cur = root;
        while (true) {
            if (cur.val <= val) {
                if (cur.right != null) {
                    cur = cur.right;
                } else {
                    cur.right = new TreeNode(val);
                    break;
                }
            } else {
                if (cur.left != null) {
                    cur = cur.left;
                } else {
                    cur.left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }

    // Function to print inorder traversal (to verify BST)
    public static void inorder(TreeNode root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.val + " ");
        inorder(root.right);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Taking input for BST
        System.out.print("Enter number of nodes in BST: ");
        int n = sc.nextInt();
        TreeNode root = null;

        System.out.println("Enter " + n + " values:");
        for (int i = 0; i < n; i++) {
            int val = sc.nextInt();
            root = insertIntoBST(root, val);
        }

        // Taking input for new value to insert
        System.out.print("Enter value to insert: ");
        int insertVal = sc.nextInt();
        root = insertIntoBST(root, insertVal);

        // Printing inorder traversal after insertion
        System.out.println("Inorder traversal after insertion:");
        inorder(root);

        sc.close();
    }
}
