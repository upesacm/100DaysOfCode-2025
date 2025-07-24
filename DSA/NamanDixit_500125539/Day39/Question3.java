import java.util.*;

public class Question3 {
    private int[] arr;
    private int top1, top2;
    private int size;

    public Question3(int capacity) {
        size = capacity;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    public void push1(int val) {
        if (top1 + 1 < top2) {
            arr[++top1] = val;
        } else {
            System.out.println("Stack Overflow in Stack 1");
        }
    }

    public void push2(int val) {
        if (top1 + 1 < top2) {
            arr[--top2] = val;
        } else {
            System.out.println("Stack Overflow in Stack 2");
        }
    }

    public int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        } else {
            System.out.println("Stack Underflow in Stack 1");
            return -1;
        }
    }

    public int pop2() {
        if (top2 < size) {
            return arr[top2++];
        } else {
            System.out.println("Stack Underflow in Stack 2");
            return -1;
        }
    }

    public List<Integer> getStack1() {
        List<Integer> stack1 = new ArrayList<>();
        for (int i = 0; i <= top1; i++) {
            stack1.add(arr[i]);
        }
        return stack1;
    }

    public List<Integer> getStack2() {
        List<Integer> stack2 = new ArrayList<>();
        for (int i = size - 1; i >= top2; i--) {
            stack2.add(arr[i]);
        }
        return stack2;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter total capacity of the dual stack: ");
        int capacity = sc.nextInt();

        Question3 ds = new Question3(capacity);

        while (true) {
            System.out.println("\nChoose operation:");
            System.out.println("1. Push in Stack 1");
            System.out.println("2. Push in Stack 2");
            System.out.println("3. Pop from Stack 1");
            System.out.println("4. Pop from Stack 2");
            System.out.println("5. Display both stacks");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");

            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter value to push in Stack 1: ");
                    int val1 = sc.nextInt();
                    ds.push1(val1);
                    break;

                case 2:
                    System.out.print("Enter value to push in Stack 2: ");
                    int val2 = sc.nextInt();
                    ds.push2(val2);
                    break;

                case 3:
                    int popped1 = ds.pop1();
                    if (popped1 != -1)
                        System.out.println("Popped from Stack 1: " + popped1);
                    break;

                case 4:
                    int popped2 = ds.pop2();
                    if (popped2 != -1)
                        System.out.println("Popped from Stack 2: " + popped2);
                    break;

                case 5:
                    System.out.println("Stack1: " + ds.getStack1());
                    System.out.println("Stack2: " + ds.getStack2());
                    break;

                case 6:
                    System.out.println("Exiting...");
                    sc.close();
                    return;

                default:
                    System.out.println("Invalid choice.");
            }
        }
    }
}
