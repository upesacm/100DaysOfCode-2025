// Filename: Question1.java

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

    // Function to convert sorted array to Balanced BST
    public static Node sortedArrayToBST(int arr[], int start, int end) {
        if (start > end) {
            return null;
        }

        // Get the middle element
        int mid = (start + end) / 2;
        Node root = new Node(arr[mid]);

        // Recursively construct left and right subtrees
        root.left = sortedArrayToBST(arr, start, mid - 1);
        root.right = sortedArrayToBST(arr, mid + 1, end);

        return root;
    }

    // Inorder traversal of BST
    public static void inorder(Node root) {
        if (root == null) {
            return;
        }
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    // Preorder traversal of BST
    public static void preorder(Node root) {
        if (root == null) {
            return;
        }
        System.out.print(root.data + " ");
        preorder(root.left);
        preorder(root.right);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Taking input from user
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter sorted array elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        Node root = sortedArrayToBST(arr, 0, n - 1);
        preorder(root);

        sc.close();
    }
}
