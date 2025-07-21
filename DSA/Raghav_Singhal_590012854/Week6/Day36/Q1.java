public class Q1 {
    static int top=-1;
    static int capacity = 100;
    static char stack[]= new char[capacity]; 

    public static void push(char value) {
        if (top == capacity - 1) {
            System.out.println("Stack Overflow");
            return;
        }
        stack[++top] = value;
    }

    public static char pop() {
        if (top ==-1) 
        {
            System.out.println("Stack Underflow");
            return '\0';
        }
        return stack[top--];
    }

    public static void reverseString(String str) {

        for (int i = 0; i < str.length(); i++)
            push(str.charAt(i));

        while (top >= 0)
            System.out.print(pop());
    }

    public static void main(String args[]) {
        String str = "hello";
        reverseString(str);
    }
}
