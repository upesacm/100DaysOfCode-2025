public class Q1 {
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
  public static void main(String[] args) {
        int[] nums = {4, 5, 2, 25};
        int[] result = nextGreater(nums);

        System.out.println("Next Greater Elements: " + Arrays.toString(result));
    }
}
