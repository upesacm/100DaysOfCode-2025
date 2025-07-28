import java.util.*;
public class Q3 {
    public static void main(String[] args) {
        Queue<Character> queue1 = new LinkedList<>(List.of('r', 'a', 'c', 'e', 'c', 'a', 'r'));
        Queue<Character> queue2 = new LinkedList<>(List.of('a', 'b', 'c'));
        System.out.println(isPalindrome(queue1));
        System.out.println(isPalindrome(queue2));
    }

    public static String isPalindrome(Queue<Character> queue) {
        Stack<Character> stack = new Stack<>();
        Queue<Character> clone = new LinkedList<>(queue);
        for (Character ch : clone) {
            stack.push(ch);
        }
        for (Character ch : clone) {
            if (!ch.equals(stack.pop())) {
                return "No";
            }
        }
        return "Yes";
    }
}
