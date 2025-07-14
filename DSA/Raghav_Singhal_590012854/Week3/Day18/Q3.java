import java.util.*;
public class Q3
{
    public static void main(String args[])
    {
        int arr[]={2, 0, 1, 2, 1, 0, 0};
        System.out.println(dutchFlag(arr));
    }
    public static String dutchFlag(int arr[])
    {
        int left=0,right=arr.length-1,temp;
        for (int i = 0; i <= right; i++) 
        {
            if(arr[i]==0)
            {
                temp=arr[left];
                arr[left]=0;
                arr[i]=temp;
                left++;
            }
            else if(arr[i]==2)
            {
                temp=arr[right];
                arr[right]=2;
                arr[i]=temp;
                right--;
                i--;
            }
        }
        return Arrays.toString(arr);
    }
}