import java.util.*;
public class Q1
{
    public static int robs(int arr[])
    {
        int n=arr.length;
        int rob[]=new int[n];
        rob[0]=arr[0];
        rob[1]=arr[1];
        for (int i = 2; i < n; i++) {
            rob[i]=rob[i-2]+arr[i];
        }
        return rob[n-1]>rob[n-2]?rob[n-1]:rob[n-2];
    }
    public static void main(String args[])
    {
        int arr[]={2, 7, 9, 3, 1};
        System.out.println(robs(arr));
    }
}