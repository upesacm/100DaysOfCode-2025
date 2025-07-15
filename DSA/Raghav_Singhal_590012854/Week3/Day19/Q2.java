public class Q2 
{
    public static void main(String[] args) 
    {
        int[] arr = {1, 3, 20, 4, 1, 0};
        System.out.println(peak(arr));
    }
    public static int peak(int[] arr) 
    {
        int left = 0, right = arr.length - 1, mid;

        while (left < right) 
        {
            mid = (right + left) / 2;
            if(arr[mid] < arr[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
}