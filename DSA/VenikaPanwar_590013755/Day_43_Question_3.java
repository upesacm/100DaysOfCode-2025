import java.util.*;

public class Day_43_Question_3 {
    public static boolean isPalindrome(Queue<Character> queue) {
        Stack<Character> stack = new Stack<>();
        int size = queue.size();

        // Copy to stack while preserving queue
        for (int i = 0; i < size; i++) {
            char ch = queue.remove();
            queue.add(ch);
            stack.push(ch);
        }

        // Compare elements from both ends
        for (int i = 0; i < size; i++) {
            char ch = queue.remove();
            char top = stack.pop();
            if (ch != top) return false;
            queue.add(ch); // Restore original queue
        }

        return true;
    }

    public static void main(String[] args) {
        Queue<Character> q1 = new LinkedList<>(Arrays.asList('r', 'a', 'c', 'e', 'c', 'a', 'r'));
        Queue<Character> q2 = new LinkedList<>(Arrays.asList('a', 'b', 'c'));

        System.out.println("Is Palindrome (racecar): " + (isPalindrome(q1) ? "Yes" : "No"));
        System.out.println("Is Palindrome (abc): " + (isPalindrome(q2) ? "Yes" : "No"));
    }
}
