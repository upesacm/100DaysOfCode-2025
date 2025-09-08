import java.util.*;

// Node definition
class BinaryTreeNode<T> {
    T data;
    BinaryTreeNode<T> left, right;

    BinaryTreeNode(T data) {
        this.data = data;
        left = right = null;
    }
}

// Pair class to store min and max
class Pair<U, V> {
    public U minimum;
    public V maximum;

    Pair(U min, V max) {
        this.minimum = min;
        this.maximum = max;
    }
}

public class Question3 {

    // Function to get min and max from Binary Tree
    public static Pair<Integer, Integer> getMinAndMax(BinaryTreeNode<Integer> root) {
        // Base case
        if (root == null) {
            return new Pair<>(Integer.MAX_VALUE, Integer.MIN_VALUE);
        }

        // Recursive calls
        Pair<Integer, Integer> leftPair = getMinAndMax(root.left);
        Pair<Integer, Integer> rightPair = getMinAndMax(root.right);

        // Small calculation
        int minimum = Math.min(root.data, Math.min(leftPair.minimum, rightPair.minimum));
        int maximum = Math.max(root.data, Math.max(leftPair.maximum, rightPair.maximum));

        return new Pair<>(minimum, maximum);
    }

    // Build tree from level order input (-1 = null)
    public static BinaryTreeNode<Integer> buildTreeLevelOrder(Scanner sc) {
        System.out.println("Enter root value (-1 for null):");
        int rootData = sc.nextInt();
        if (rootData == -1) return null;

        BinaryTreeNode<Integer> root = new BinaryTreeNode<>(rootData);
        Queue<BinaryTreeNode<Integer>> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            BinaryTreeNode<Integer> current = queue.poll();

            System.out.println("Enter left child of " + current.data + " (-1 for null):");
            int leftData = sc.nextInt();
            if (leftData != -1) {
                current.left = new BinaryTreeNode<>(leftData);
                queue.add(current.left);
            }

            System.out.println("Enter right child of " + current.data + " (-1 for null):");
            int rightData = sc.nextInt();
            if (rightData != -1) {
                current.right = new BinaryTreeNode<>(rightData);
                queue.add(current.right);
            }
        }
        return root;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Build tree
        BinaryTreeNode<Integer> root = buildTreeLevelOrder(sc);

        // Get min and max
        Pair<Integer, Integer> ans = getMinAndMax(root);

        System.out.println("Minimum value in tree: " + ans.minimum);
        System.out.println("Maximum value in tree: " + ans.maximum);

        sc.close();
    }
}
