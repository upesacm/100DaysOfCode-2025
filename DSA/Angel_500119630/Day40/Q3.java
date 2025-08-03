class Q3 {
    private Stack<Integer> s;
    private int maxEle;

    public MaxStack() {
        s = new Stack<>();
        maxEle = -1;
    }
    public void push(int x) {
        if (s.isEmpty()) {
            maxEle = x;
            s.push(x);
        }
        else if (x > maxEle) {
            s.push(2 * x - maxEle);
            maxEle = x;
        } else {
            s.push(x);
        }
    }

    public void pop() {
        if (s.isEmpty()) {
            return;
        }

        int top = s.pop();

      
        if (top > maxEle) {
            maxEle = 2 * maxEle - top;
        }
    }

    public int peek() {
        if (s.isEmpty()) {
            return -1;
        }

        int top = s.peek();

        return (maxEle < top) ? maxEle : top;
    }

    public int getMax() {
        if (s.isEmpty()) {
            return -1;
        }

       
        return maxEle;
    }

    public static void main(String[] args) {
        MaxStack stk = new MaxStack();

        stk.push(2);
        stk.push(3);
        System.out.print(stk.peek() + " ");
        stk.pop();
        System.out.print(stk.getMax() + " ");
        stk.push(1);
        System.out.print(stk.getMax() + " ");
    }
}
