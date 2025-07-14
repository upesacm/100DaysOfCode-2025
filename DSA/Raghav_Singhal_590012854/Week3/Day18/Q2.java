import java.util.*;
public class Q2
{
    public static void main(String[] args) {
        int arr[]={12, 11, 13, 5, 6};
        System.out.println(inserSort(arr));
    }
    public static String inserSort(int arr[])
    {
        for (int i = 1; i < arr.length; i++) 
        {
            int key=arr[i];
            int j=i-1;  
            while (j>=0 && key<arr[j])
            {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
        return Arrays.toString(arr);
    }
}