public class Q3 {
    public static void main(String[] args) 
    {
        int matrix[][] ={{1,4,7},{2,5,8},{3,6,9}},target = 5;
        System.out.println(searchMatrix(matrix, target));
    }
    public static boolean searchMatrix(int matrix[][], int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) return false;
        int m = matrix.length, n = matrix[0].length;
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midVal = matrix[mid / n][mid % n];
            if (midVal == target) {
                return true;
            } else if (midVal < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
}
