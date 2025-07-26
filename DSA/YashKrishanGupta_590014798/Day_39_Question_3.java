public class Day_39_Question_3 {
    static class DualStack {
        int[] arr;
        int top1, top2;

        public DualStack(int n) {
            arr = new int[n];
            top1 = -1;
            top2 = n;
        }

        public void push1(int val) {
            if (top1 + 1 < top2) {
                arr[++top1] = val;
            } else {
                throw new RuntimeException("Stack Overflow");
            }
        }

        public void push2(int val) {
            if (top1 + 1 < top2) {
                arr[--top2] = val;
            } else {
                throw new RuntimeException("Stack Overflow");
            }
        }

        public int pop1() {
            if (top1 >= 0) {
                return arr[top1--];
            }
            throw new RuntimeException("Stack 1 Underflow");
        }

        public int pop2() {
            if (top2 < arr.length) {
                return arr[top2++];
            }
            throw new RuntimeException("Stack 2 Underflow");
        }

        public boolean isFull() {
            return top1 + 1 == top2;
        }

        public void printStack1() {
            if (top1 < 0) {
                System.out.println("Stack 1 is empty");
                return;
            }
            System.out.print("Stack 1 (bottom → top): ");
            for (int i = 0; i <= top1; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
        }

        public void printStack2() {
            if (top2 >= arr.length) {
                System.out.println("Stack 2 is empty");
                return;
            }
            System.out.print("Stack 2 (bottom → top): ");
            for (int i = arr.length - 1; i >= top2; i--) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        DualStack st = new DualStack(50);
        st.push1(1);
        st.push1(2);
        st.push2(8);
        st.push2(9);
        st.printStack1();
        st.printStack2();
        st.push1(3);
        st.pop2();
        st.printStack1();
        st.printStack2();
    }
}
