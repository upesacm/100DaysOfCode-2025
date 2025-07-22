public class Q3 {
    public static void main(String[] args) {
        int nums[]={1,2,3};
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