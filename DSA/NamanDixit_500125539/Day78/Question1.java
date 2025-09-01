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

public class Question1 {

    // Function to search in BST
    public static boolean searchBST(TreeNode root, int val) {
        while (root != null) {
            if (root.val == val) {
                return true;
            }
            root = val < root.val ? root.left : root.right;
        }
        return false;
    }

    // Function to insert nodes in BST
    public static TreeNode insert(TreeNode root, int val) {
        if (root == null) {
            return new TreeNode(val);
        }
        if (val < root.val) {
            root.left = insert(root.left, val);
        } else {
            root.right = insert(root.right, val);
        }
        return root;
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
            root = insert(root, val);
        }

        // Taking input for search value
        System.out.print("Enter key to search: ");
        int key = sc.nextInt();

        // Searching
        if (searchBST(root, key)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

        sc.close();
    }
}
