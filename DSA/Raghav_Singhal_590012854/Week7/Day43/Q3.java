import java.util.*;

public class Q3 {

    public static boolean isPalindrome(Queue<Character> queue) {
        Stack<Character> stack = new Stack<>();
        int size = queue.size();

        for (int i = 0; i < size; i++) {
            char ch = queue.poll();
            stack.push(ch);
            queue.offer(ch); 
        }

        for (int i = 0; i < size; i++) {
            char chQueue = queue.poll();
            char chStack = stack.pop();

            if (chQueue != chStack) {
                return false;
            }
            queue.offer(chQueue); 
        }

        return true;
    }

    public static void main(String[] args) {
        Queue<Character> queue = new LinkedList<>(List.of('r', 'a', 'c', 'e', 'c', 'a', 'r'));
        System.out.println(isPalindrome(queue));
    }
}
