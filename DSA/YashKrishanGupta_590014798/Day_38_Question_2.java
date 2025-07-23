import java.util.Stack;
public class Day_38_Question_2 {
    public static class MinStack{
        private Stack<Integer> st = new Stack<>();
        private Stack<Integer> min = new Stack<>();

        public void push(int val){
            st.push(val);
            if(min.isEmpty() || min.peek() >= val) min.push(val);
        }

        public Integer pop(){
            if(st.isEmpty()) return null;
            int val = st.pop();
            if(val == min.peek()) min.pop();
            return val;
        }

        public Integer top(){
            if(st.isEmpty()) return null;
            return st.peek();
        }

        public Integer getMin(){
            if(min.isEmpty()) return null;
            return min.peek();
        }

        public boolean isEmpty(){
            return st.isEmpty();
        }
    }
    public static void main(String[] args) {
        MinStack minStack = new MinStack();
        minStack.push(8);
        minStack.push(2);
        minStack.push(6);
        minStack.pop();
        System.out.println(minStack.getMin());
    }
}
