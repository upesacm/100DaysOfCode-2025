class Q1 {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        Stack<Integer> stack = new Stack<>();

        Arrays.fill(result, -1);
        for(int i = 0 ; i < n ; i++){
            while(!stack.isEmpty() && nums[i]>nums[stack.peek()]){
                
                    int index = stack.pop();
                    result[index]=nums[i];
                
            }
            stack.push(i);
        }
        return result;
    }
}
