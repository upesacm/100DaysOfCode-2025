
public class Q3 {

    static int[] arr = new int[10];
    static int top1 = -1;
    static int top2 = 10;

    public static void push1(int x) {
        if (top1 + 1 == top2) {
            throw new RuntimeException("Overflow: no space left");
        }
        arr[++top1] = x;
    }

    public static int pop1() {
        if (top1 == -1) {
            throw new RuntimeException("Underflow: stack1 empty");
        }
        return arr[top1--];
    }

    public static int peek1() {
        if (top1 == -1) {
            throw new RuntimeException("stack1 empty");
        }
        return arr[top1];
    }

    public static boolean isEmpty1() {
        return top1 == -1;
    }

    public static int size1() {
        return top1 + 1;
    }

    public static void push2(int x) {
        if (top2 - 1 == top1) {
            throw new RuntimeException("Overflow: no space left");
        }
        arr[--top2] = x;
    }

    public static int pop2() {
        if (top2 == arr.length) {
            throw new RuntimeException("Underflow: stack2 empty");
        }
        return arr[top2++];
    }

    public static int peek2() {
        if (top2 == arr.length) {
            throw new RuntimeException("stack2 empty");
        }
        return arr[top2];
    }

    public static boolean isEmpty2() {
        return top2 == arr.length;
    }

    public static int size2() {
        return arr.length - top2;
    }

    public static void printStacks() {
        System.out.print("Stack1 : ");
        for (int i = 0; i <= top1; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

        System.out.print("Stack2 : ");
        for (int i = arr.length - 1; i >= top2; i--) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {

        push1(1);
        push1(2);

        push2(8);
        push2(9);
        System.out.println("After 1st Operaation");
        printStacks();
        push1(3);
        pop2();
        System.out.println("After 2nd Operaation");
        printStacks();
    }
}
