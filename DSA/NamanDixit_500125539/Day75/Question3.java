import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        left = right = null;
    }
}

public class Question3 {

    // Build tree from level-order input
    public static Node buildTreeLevelOrder(int n, Scanner sc) {
        if (n == 0) return null;

        int val = sc.nextInt();
        if (val == -1) return null;

        Node root = new Node(val);
        Queue<Node> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            Node temp = q.poll();

            // left child
            if (sc.hasNextInt()) {
                int leftVal = sc.nextInt();
                if (leftVal != -1) {
                    temp.left = new Node(leftVal);
                    q.add(temp.left);
                }
            }

            // right child
            if (sc.hasNextInt()) {
                int rightVal = sc.nextInt();
                if (rightVal != -1) {
                    temp.right = new Node(rightVal);
                    q.add(temp.right);
                }
            }
        }
        return root;
    }

    // Diameter of Binary Tree (Iterative)
    public static int diameterOfBinaryTree(Node root) {
        if (root == null) return 0;

        Map<Node, Integer> map = new HashMap<>();
        Stack<Node> stack = new Stack<>();
        stack.push(root);
        int diameter = 0;

        while (!stack.isEmpty()) {
            Node node = stack.peek();

            // Fill stack for post-order traversal
            if (node.left != null && !map.containsKey(node.left)) {
                stack.push(node.left);
            } else if (node.right != null && !map.containsKey(node.right)) {
                stack.push(node.right);
            } else {
                // Process the node
                stack.pop();

                int leftDepth = map.getOrDefault(node.left, 0);
                int rightDepth = map.getOrDefault(node.right, 0);

                // Update depth of current node
                map.put(node, 1 + Math.max(leftDepth, rightDepth));

                // Update diameter
                diameter = Math.max(diameter, leftDepth + rightDepth);
            }
        }

        return diameter;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        System.out.println("Enter nodes in level order (-1 for null):");
        Node root = buildTreeLevelOrder(n, sc);

        int diameter = diameterOfBinaryTree(root);
        System.out.println("Diameter of Binary Tree: " + diameter);
    }
}
