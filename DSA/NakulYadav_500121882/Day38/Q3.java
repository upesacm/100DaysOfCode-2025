public class Q3 {
    public boolean hasRedundantBrackets(String expression) {
        Stack<Character> stack = new Stack<>();

        for (char ch : expression.toCharArray()) {
            if (ch == ')') {
                boolean hasOperator = false;

                while (!stack.isEmpty() && stack.peek() != '(') {
                    char top = stack.pop();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        hasOperator = true;
                    }
                }

                if (!stack.isEmpty()) stack.pop(); 

                if (!hasOperator) return true; 
            } else {
                stack.push(ch);
            }
        }

        return false;
    }
