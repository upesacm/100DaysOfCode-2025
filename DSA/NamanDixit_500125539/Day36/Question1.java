
import java.util.*;

class Question1 {

    static void reverseStack(String str) {
        //Work using First in last out method
        Stack<Character> stack = new Stack<>();
        for (Character c : str.toCharArray()) {
            stack.push(c);

        }
        System.out.print("Reversed string: ");
        for (Character c : str.toCharArray()) {
            System.out.print(stack.pop());

        }

    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter String: ");
        String str = sc.nextLine();
        reverseStack(str);

    }
}
