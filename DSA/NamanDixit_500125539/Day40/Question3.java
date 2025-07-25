import java.util.*;

public class Question3 {

    private Stack<Integer> mainStack;
    private Stack<Integer> maxStack;

    public Question3() {
        mainStack = new Stack<>();
        maxStack = new Stack<>();
    }

    public void push(int val) {
        mainStack.push(val);
        if (maxStack.isEmpty() || val >= maxStack.peek()) {
            maxStack.push(val);
        } else {
            maxStack.push(maxStack.peek());
        }
    }

    public void pop() {
        if (!mainStack.isEmpty()) {
            mainStack.pop();
            maxStack.pop();
        } else {
            System.out.println("Stack is empty. Cannot pop.");
        }
    }

    public int getMax() {
        if (!maxStack.isEmpty()) {
            return maxStack.peek();
        } else {
            System.out.println("Stack is empty.");
            return -1;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Question3 stack = new Question3();

        System.out.println("Enter operations (push <num>, pop, getMax, exit):");

        while (true) {
            String input = sc.nextLine().trim();
            String[] parts = input.split(" ");

            if (parts[0].equalsIgnoreCase("push")) {
                int num = Integer.parseInt(parts[1]);
                stack.push(num);
            } else if (parts[0].equalsIgnoreCase("pop")) {
                stack.pop();
            } else if (parts[0].equalsIgnoreCase("getMax")) {
                int max = stack.getMax();
                if (max != -1)
                    System.out.println(max);
            } else if (parts[0].equalsIgnoreCase("exit")) {
                break;
            } else {
                System.out.println("Invalid command. Try: push <num>, pop, getMax, exit");
            }
        }

        sc.close();
    }
}
