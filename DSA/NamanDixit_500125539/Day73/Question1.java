import java.util.*;

// Binary Tree Node class
class BinaryTreeNode<T> {
    T data;
    BinaryTreeNode<T> left;
    BinaryTreeNode<T> right;

    BinaryTreeNode(T data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

public class Question1 {

    // Function to calculate sum of nodes
    public static int getSum(BinaryTreeNode<Integer> root) {
        if (root == null) {
            return 0;
        }
        int rootData = root.data;
        int left = getSum(root.left);
        int right = getSum(root.right);
        return rootData + left + right;
    }

    // Function to take tree input level-wise
    public static BinaryTreeNode<Integer> takeInput() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter root data: ");
        int rootData = sc.nextInt();

        if (rootData == -1) {
            return null;
        }

        BinaryTreeNode<Integer> root = new BinaryTreeNode<>(rootData);
        Queue<BinaryTreeNode<Integer>> pendingNodes = new LinkedList<>();
        pendingNodes.add(root);

        while (!pendingNodes.isEmpty()) {
            BinaryTreeNode<Integer> front = pendingNodes.poll();

            System.out.println("Enter left child of " + front.data + ": ");
            int leftData = sc.nextInt();
            if (leftData != -1) {
                BinaryTreeNode<Integer> leftChild = new BinaryTreeNode<>(leftData);
                front.left = leftChild;
                pendingNodes.add(leftChild);
            }

            System.out.println("Enter right child of " + front.data + ": ");
            int rightData = sc.nextInt();
            if (rightData != -1) {
                BinaryTreeNode<Integer> rightChild = new BinaryTreeNode<>(rightData);
                front.right = rightChild;
                pendingNodes.add(rightChild);
            }
        }
        return root;
    }

    // Main method
    public static void main(String[] args) {
        BinaryTreeNode<Integer> root = takeInput();
        int sum = getSum(root);
        System.out.println(sum);
    }
}
