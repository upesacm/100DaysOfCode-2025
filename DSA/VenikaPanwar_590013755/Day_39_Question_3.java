import java.util.*;

class TwoStacks {
    int[] arr;
    int top1, top2, size;

    public TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }

    public void push1(int x) {
        if (top1 + 1 < top2) {
            arr[++top1] = x;
        } else {
            System.out.println("Stack1 Overflow");
        }
    }

    public void push2(int x) {
        if (top1 + 1 < top2) {
            arr[--top2] = x;
        } else {
            System.out.println("Stack2 Overflow");
        }
    }

    public int pop1() {
        return (top1 >= 0) ? arr[top1--] : -1;
    }

    public int pop2() {
        return (top2 < size) ? arr[top2++] : -1;
    }

    public void printStacks() {
        System.out.print("Stack1: ");
        for (int i = 0; i <= top1; i++) System.out.print(arr[i] + " ");
        System.out.print("\nStack2: ");
        for (int i = size - 1; i >= top2; i--) System.out.print(arr[i] + " ");
        System.out.println();
    }
}

public class TwoStacksInArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        TwoStacks ts = new TwoStacks(10);

        ts.push1(1);
        ts.push1(2);
        ts.push2(9);
        ts.push2(8);
        ts.printStacks();

        ts.push1(3);
        ts.pop2();
        ts.printStacks();
    }
}
