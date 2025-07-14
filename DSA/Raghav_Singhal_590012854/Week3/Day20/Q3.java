public class Q3
{
    public static void main(String args[])
    {
        int[] Array = {3, 2, 1, 5, 6, 4};
        int k = 5;
        System.out.println(kthEle(Array, k));
    }
    public static int kthEle(int arr[], int k)
    {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
        return arr[k - 1];
    }
}