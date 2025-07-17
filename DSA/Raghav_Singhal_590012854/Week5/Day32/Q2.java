public class Q2 {
    public static void main(String[] args) {
        int nums[]={2,3,2};
        System.out.println(nonRepeat(nums));
    }
    public static int nonRepeat(int[] nums) 
    {
        int no = 0;
        for (int num : nums)
            no ^= num;
        return no;
    }
}