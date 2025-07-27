import java.util.*;
public class Day_40_Question_3 {
    static class MaxStack {
        private Stack<Integer> mainStack = new Stack<>();;
        private Stack<Integer> maxStack = new Stack<>();;

        public void push(int x) {
            mainStack.push(x);
            if (maxStack.isEmpty()) {
                maxStack.push(x);
            } else {
                maxStack.push(Math.max(x, maxStack.peek()));
            }
        }

        public void pop() {
            if (!mainStack.isEmpty()) {
                mainStack.pop();
                maxStack.pop();
            }
        }

        public int top() {
            return mainStack.peek();
        }

        public int getMax() {
            return maxStack.peek();
        }

        public boolean isEmpty() {
            return mainStack.isEmpty();
        }
    }
