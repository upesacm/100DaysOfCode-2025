class Q2 {

    static int[] nextSmaller(int[] arr) {
        int n = arr.length;

        int[] nextS = new int[n];
        for (int i = 0; i < n; i++) {
            nextS[i] = n;
        }

        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && arr[i] < arr[st.peek()]) {

                // Setting the index of the next smaller element
                // for the top of the stack
                nextS[st.pop()] = i;
            }
            st.push(i);
        }
        return nextS;
    }

    static int[] prevSmaller(int[] arr) {
        int n = arr.length;

        int[] prevS = new int[n];
        for (int i = 0; i < n; i++) {
            prevS[i] = -1;
        }

        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && arr[i] < arr[st.peek()]) {
                st.pop();
            }
            if (!st.isEmpty()) {
                prevS[i] = st.peek();
            }
            st.push(i);
        }
        return prevS;
    }

   
    static int getMaxArea(int[] arr) {
        int[] prevS = prevSmaller(arr);
        int[] nextS = nextSmaller(arr);
        int maxArea = 0;

        for (int i = 0; i < arr.length; i++) {
            int width = nextS[i] - prevS[i] - 1;
            int area = arr[i] * width;
            maxArea = Math.max(maxArea, area);
        }
        return maxArea;
    }

    public static void main(String[] args) {
        int[] arr = {60, 20, 50, 40, 10, 50, 60};
        System.out.println(getMaxArea(arr));
    }
}
