import java.util.*;

// Binary Tree Node class
class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

public class Question2 {

    // Function for Level Order Traversal
    public static List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> wrapList = new LinkedList<>();

        if (root == null) return wrapList;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            int levelNum = queue.size();
            List<Integer> subList = new LinkedList<>();

            for (int i = 0; i < levelNum; i++) {
                if (queue.peek().left != null) queue.offer(queue.peek().left);
                if (queue.peek().right != null) queue.offer(queue.peek().right);
                subList.add(queue.poll().val);
            }
            wrapList.add(subList);
        }
        return wrapList;
    }

    // Function to build tree level-wise using user input
    public static TreeNode takeInput() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter root data: ");
        int rootData = sc.nextInt();

        if (rootData == -1) {
            return null;
        }

        TreeNode root = new TreeNode(rootData);
        Queue<TreeNode> pendingNodes = new LinkedList<>();
        pendingNodes.add(root);

        while (!pendingNodes.isEmpty()) {
            TreeNode front = pendingNodes.poll();

            System.out.println("Enter left child of " + front.val + ": ");
            int leftData = sc.nextInt();
            if (leftData != -1) {
                TreeNode leftChild = new TreeNode(leftData);
                front.left = leftChild;
                pendingNodes.add(leftChild);
            }

            System.out.println("Enter right child of " + front.val + ": ");
            int rightData = sc.nextInt();
            if (rightData != -1) {
                TreeNode rightChild = new TreeNode(rightData);
                front.right = rightChild;
                pendingNodes.add(rightChild);
            }
        }
        return root;
    }

    // Main Method
    public static void main(String[] args) {
        TreeNode root = takeInput();
        List<List<Integer>> result = levelOrder(root);

        for (List<Integer> level : result) {
            System.out.print(level);
        }
    }
}
