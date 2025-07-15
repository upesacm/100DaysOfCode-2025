
import java.util.Arrays;

public class Q1 {
    public static void main(String[] args)
    {
        int arr[] = {29, 10, 14, 37, 13};
        System.out.println(selecSort(arr));
    }
    public static String selecSort(int arr[])
    {
        for (int i = 0; i < arr.length - 1; i++) 
        {
            int min = i;
            for (int j = i + 1; j < arr.length; j++)
                if (arr[j] < arr[min])
                    min = j;
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
        return Arrays.toString(arr);
    }
}
