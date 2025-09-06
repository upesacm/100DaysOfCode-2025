// File: Question2.java
import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        left = right = null;
    }
}

public class Question2 {
    Node root;
    Node headLinkedList = null; // Head of Doubly Linked List
    Node prev = null;           // Previous node for linking

    // Insert into BST
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

    // Convert BST to Doubly Linked List
    public void bstToDoublyLinkedList(Node node) {
        if (node == null) return;

        // Inorder traversal
        bstToDoublyLinkedList(node.left);

        if (prev == null) {
            headLinkedList = node; // First node is head
        } else {
            node.left = prev;
            prev.right = node;
        }

        prev = node;

        bstToDoublyLinkedList(node.right);
    }

    // Print the Doubly Linked List
    public void printList() {
        Node node = headLinkedList;
        System.out.println("Doubly Linked List in sorted order:");
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.right;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Question2 bst = new Question2();

        // Input number of nodes
        System.out.print("Enter number of nodes in BST: ");
        int n = sc.nextInt();

        // Input node values
        System.out.println("Enter " + n + " node values:");
        for (int i = 0; i < n; i++) {
            int val = sc.nextInt();
            bst.root = bst.insert(bst.root, val);
        }

        // Convert BST to DLL
        bst.bstToDoublyLinkedList(bst.root);

        // Print DLL
        bst.printList();

        sc.close();
    }
}
