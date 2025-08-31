import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

public class Question3 {

    // Function to count nodes at a given level using BFS
    public static int countNodesAtLevel(Node root, int level) {
        if (root == null) return 0;

        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);

        int currentLevel = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();

            // If we are at the target level, return number of nodes
            if (currentLevel == level) {
                return size;
            }

            // Process next level
            for (int i = 0; i < size; i++) {
                Node curr = queue.poll();
                if (curr.left != null) queue.offer(curr.left);
                if (curr.right != null) queue.offer(curr.right);
            }

            currentLevel++;
        }

        return 0; // If level is greater than tree height
    }

    // Build tree from user input (level order)
    public static Node buildTree(Scanner sc) {
        System.out.print("Enter root value (-1 for NULL): ");
        int val = sc.nextInt();
        if (val == -1) return null;

        Node root = new Node(val);
        Queue<Node> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            Node curr = q.poll();

            System.out.print("Enter left child of " + curr.data + " (-1 for NULL): ");
            int leftVal = sc.nextInt();
            if (leftVal != -1) {
                curr.left = new Node(leftVal);
                q.add(curr.left);
            }

            System.out.print("Enter right child of " + curr.data + " (-1 for NULL): ");
            int rightVal = sc.nextInt();
            if (rightVal != -1) {
                curr.right = new Node(rightVal);
                q.add(curr.right);
            }
        }
        return root;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Build tree
        Node root = buildTree(sc);

        System.out.print("Enter the level to count nodes: ");
        int level = sc.nextInt();

        int count = countNodesAtLevel(root, level);

        System.out.println("Number of nodes at level " + level + ": " + count);
    }
}
