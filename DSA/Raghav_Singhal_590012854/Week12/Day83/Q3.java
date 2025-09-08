import java.util.*;

class Q3 {
    public static void inorder(Node root, List<Integer> list) {
        if (root == null) return;
        inorder(root.left, list);
        list.add(root.data);
        inorder(root.right, list);
    }

    public static boolean findTarget(Node root, int target) {
        List<Integer> list = new ArrayList<>();
        inorder(root, list);
        int l = 0, r = list.size() - 1;
        while (l < r) {
            int sum = list.get(l) + list.get(r);
            if (sum == target) return true;
            if (sum < target) l++;
            else r--;
        }
        return false;
    }

    public static void main(String[] args) {
        Node root = new Node(5);
        root.left = new Node(3);
        root.right = new Node(6);
        root.left.left = new Node(2);
        root.left.right = new Node(4);
        root.right.right = new Node(7);

        System.out.println(findTarget(root, 9) ? "Yes" : "No");
        System.out.println(findTarget(root, 28) ? "Yes" : "No");
    }
}
