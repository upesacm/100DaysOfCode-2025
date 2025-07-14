public class Q1 {
    public static void main(String[] args) 
    {
        int[] arr = {4, 5, 6, 7, 0, 1, 2};
        int target = 7;
        System.out.println(search(arr, target));
    }
    public static int search(int[] arr, int target) 
    {
        int left = 0, right = arr.length - 1, mid;

        while (left <= right) 
        {
            mid = (right + left) / 2;
            if (arr[mid] == target)
                return mid;
            if (arr[left] <= arr[mid]) 
                if (arr[left] <= target && target < arr[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            else
                if (arr[mid] < target && target <= arr[right])
                    left = mid + 1;
                else
                    right = mid - 1;
        }
        return -1;
    }
}
