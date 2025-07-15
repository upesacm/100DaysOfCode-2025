public class Q1 {
    public static void main(String args[])
    {
        int array[]= {1, 3, 5, 7, 9, 11}, Target=7;
        System.out.println(binarySearch(array,Target));
    }
    public static String binarySearch(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        while (left <= right) 
        {
            int mid = (left + right) / 2;
            if (arr[mid] == target) 
                return String.valueOf(mid);
            else if (arr[mid] < target) 
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return "Target not Found";
    }
}