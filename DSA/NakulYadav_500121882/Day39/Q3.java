public class Q3 {
    public static void main(String[] args) {
        DualStack ds = new DualStack(10);
        ds.push1(1);
        ds.push1(2);
        ds.push2(9);
        ds.push2(8);
        ds.push1(3);
        ds.pop2();
        ds.printStacks();
    }
}

class DualStack {
    int[] arr;
    int top1, top2;

    DualStack(int size) {
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int val) {
        if (top1 + 1 < top2) {
            arr[++top1] = val;
        } else {
            System.out.println("Stack Overflow - Stack1");
        }
    }

    void push2(int val) {
        if (top1 + 1 < top2) {
            arr[--top2] = val;
        } else {
            System.out.println("Stack Overflow - Stack2");
        }
    }

    int pop1() {
        if (top1 >= 0) return arr[top1--];
        System.out.println("Stack Underflow - Stack1");
        return -1;
    }

    int pop2() {
        if (top2 < arr.length) return arr[top2++];
        System.out.println("Stack Underflow - Stack2");
        return -1;
    }

    void printStacks() {
        System.out.print("Stack1: ");
        for (int i = 0; i <= top1; i++) System.out.print(arr[i] + " ");
        System.out.print("\nStack2: ");
        for (int i = arr.length - 1; i >= top2; i--) System.out.print(arr[i] + " ");
        System.out.println();
    }
}
