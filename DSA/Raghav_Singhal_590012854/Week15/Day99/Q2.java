import java.util.*;

class Q2 {
    static class MaxStack {
        Stack<Integer> stack = new Stack<>();
        Stack<Integer> maxStack = new Stack<>();

        void push(int x) {
            stack.push(x);
            if (maxStack.isEmpty() || x >= maxStack.peek()) {
                maxStack.push(x);
            } else {
                maxStack.push(maxStack.peek());
            }
        }

        int pop() {
            maxStack.pop();
            return stack.pop();
        }

        int getMax() {
            return maxStack.peek();
        }

        boolean isEmpty() {
            return stack.isEmpty();
        }
    }

    public static List<Integer> maxSlidingWindow(int[] nums, int k) {
        List<Integer> result = new ArrayList<>();
        MaxStack s1 = new MaxStack(), s2 = new MaxStack();

        for (int i = 0; i < nums.length; i++) {
            s1.push(nums[i]);

            if (i >= k) {
                if (s2.isEmpty()) {
                    while (!s1.isEmpty()) {
                        int val = s1.pop();
                        s2.push(val);
                    }
                }
                s2.pop();
            }

            if (i >= k - 1) {
                int maxVal = s2.isEmpty() ? s1.getMax() : s1.isEmpty() ? s2.getMax() : Math.max(s1.getMax(), s2.getMax());
                result.add(maxVal);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 3, -1, -3, 5, 3, 6, 7};
        System.out.println(maxSlidingWindow(arr1, 3)); // [3, 3, 5, 5, 6, 7]

        int[] arr2 = {4, 2, 1, 5};
        System.out.println(maxSlidingWindow(arr2, 2)); // [4, 2, 5]
    }
}
