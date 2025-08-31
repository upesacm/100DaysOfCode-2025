import java.util.*;

// Definition for a binary tree node
class Node {
    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

public class Question2 {

    // Recursive helper to find kth ancestor
    static Node solve(Node root, int node, int[] k) {
        if (root == null) return null;

        // If we found the target node
        if (root.data == node) {
            return root;
        }

        // Search in left and right subtrees
        Node leftAns = solve(root.left, node, k);
        Node rightAns = solve(root.right, node, k);

        // If node is found in either subtree
        if (leftAns != null || rightAns != null) {
            k[0]--;  // decrease k when backtracking

            // If k == 0, this is the ancestor
            if (k[0] == 0) {
                // Lock answer by setting k to max value
                k[0] = Integer.MAX_VALUE;
                return root;
            }

            // Return whichever side has the answer
            return (leftAns != null) ? leftAns : rightAns;
        }

        return null;
    }

    // Function to find kth ancestor
    public static int kthAncestor(Node root, int k, int node) {
        int[] K = {k}; // use array to simulate pass-by-reference
        Node ans = solve(root, node, K);

        // If ancestor exists and is not the node itself
        if (ans == null || ans.data == node) {
            return -1;
        }
        return ans.data;
    }

    // Build tree (level-order)
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

        // Build binary tree from user input
        Node root = buildTree(sc);

        System.out.print("Enter node value: ");
        int node = sc.nextInt();
        System.out.print("Enter K: ");
        int k = sc.nextInt();

        int ans = kthAncestor(root, k, node);
        System.out.println("Kth ancestor of node " + node + " is: " + ans);
    }
}
