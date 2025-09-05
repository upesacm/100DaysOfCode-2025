// File: Question3.java
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
    Node root;

    // Insert a node into BST
    public Node insert(Node root, int data) {
        if (root == null) {
            return new Node(data);
        }
        if (data < root.data) {
            root.left = insert(root.left, data);
        } else {
            root.right = insert(root.right, data);
        }
        return root;
    }

    // Function to count nodes in range [low, high]
    public int getCount(Node root, int low, int high) {
        if (root == null) {
            return 0;
        }

        // If current node is in range
        if (root.data >= low && root.data <= high) {
            return 1 + getCount(root.left, low, high) + getCount(root.right, low, high);
        }
        // If current node is smaller than low, go to right child
        else if (root.data < low) {
            return getCount(root.right, low, high);
        }
        // If current node is greater than high, go to left child
        else {
            return getCount(root.left, low, high);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Question3 bst = new Question3();

        // Input number of nodes
        System.out.print("Enter number of nodes in BST: ");
        int n = sc.nextInt();

        // Input node values
        System.out.println("Enter " + n + " node values:");
        for (int i = 0; i < n; i++) {
            int val = sc.nextInt();
            bst.root = bst.insert(bst.root, val);
        }

        // Input range
        System.out.print("Enter low value: ");
        int low = sc.nextInt();
        System.out.print("Enter high value: ");
        int high = sc.nextInt();

        // Count nodes in range
        int count = bst.getCount(bst.root, low, high);
        System.out.println(count);

        sc.close();
    }
}
