import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        left = right = null;
    }
}

public class Question1 {

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

    // Utility function for Left View
    static void printLeftViewUtil(Node root, ArrayList<Node> list, int level) {
        if (root == null) return;

        if (list.size() == level) {
            list.add(root);
        }

        printLeftViewUtil(root.left, list, level + 1);
        printLeftViewUtil(root.right, list, level + 1);
    }

    // Print Left View
    static void printLeftView(Node root) {
        ArrayList<Node> list = new ArrayList<>();
        printLeftViewUtil(root, list, 0);

        for (Node cur : list) {
            System.out.print(cur.data + " ");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        System.out.println("Enter nodes in level order (-1 for null):");
        Node root = buildTreeLevelOrder(n, sc);

        printLeftView(root);
    }
}
