import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

public class Question1 {

    // Function to build tree from user input (level order)
    public static TreeNode buildTree(Scanner sc) {
        System.out.println("Enter root value (-1 for null):");
        int rootVal = sc.nextInt();
        if (rootVal == -1) return null;

        TreeNode root = new TreeNode(rootVal);
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            TreeNode current = queue.poll();

            System.out.println("Enter left child of " + current.val + " (-1 for null):");
            int leftVal = sc.nextInt();
            if (leftVal != -1) {
                current.left = new TreeNode(leftVal);
                queue.offer(current.left);
            }

            System.out.println("Enter right child of " + current.val + " (-1 for null):");
            int rightVal = sc.nextInt();
            if (rightVal != -1) {
                current.right = new TreeNode(rightVal);
                queue.offer(current.right);
            }
        }
        return root;
    }

    // Mark parents using BFS
    private static void markParents(TreeNode root, Map<TreeNode, TreeNode> parent_track, TreeNode target) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            TreeNode current = queue.poll();

            if (current.left != null) {
                parent_track.put(current.left, current);
                queue.offer(current.left);
            }
            if (current.right != null) {
                parent_track.put(current.right, current);
                queue.offer(current.right);
            }
        }
    }

    // Find nodes at distance K
    public static List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        Map<TreeNode, TreeNode> parent_track = new HashMap<>();
        markParents(root, parent_track, root);

        Map<TreeNode, Boolean> visited = new HashMap<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(target);
        visited.put(target, true);

        int curr_level = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            if (curr_level == k) break;
            curr_level++;

            for (int i = 0; i < size; i++) {
                TreeNode current = queue.poll();

                if (current.left != null && visited.get(current.left) == null) {
                    queue.offer(current.left);
                    visited.put(current.left, true);
                }
                if (current.right != null && visited.get(current.right) == null) {
                    queue.offer(current.right);
                    visited.put(current.right, true);
                }
                if (parent_track.get(current) != null && visited.get(parent_track.get(current)) == null) {
                    queue.offer(parent_track.get(current));
                    visited.put(parent_track.get(current), true);
                }
            }
        }

        List<Integer> result = new ArrayList<>();
        while (!queue.isEmpty()) {
            TreeNode current = queue.poll();
            result.add(current.val);
        }
        return result;
    }

    // Main function
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Build tree from user input
        TreeNode root = buildTree(sc);

        // Get target node value
        System.out.println("Enter target node value:");
        int targetVal = sc.nextInt();

        // Find target node reference
        TreeNode target = findNode(root, targetVal);

        if (target == null) {
            System.out.println("Target node not found!");
            return;
        }

        // Get distance K
        System.out.println("Enter distance K:");
        int k = sc.nextInt();

        // Find nodes at distance K
        List<Integer> result = distanceK(root, target, k);

        System.out.println(result);
    }

    // Helper function to find node by value
    public static TreeNode findNode(TreeNode root, int val) {
        if (root == null) return null;
        if (root.val == val) return root;

        TreeNode leftSearch = findNode(root.left, val);
        if (leftSearch != null) return leftSearch;

        return findNode(root.right, val);
    }
}
