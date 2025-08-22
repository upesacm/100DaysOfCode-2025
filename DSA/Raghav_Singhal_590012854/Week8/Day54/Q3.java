

public class Q3 {
    public static void main(String args[])
    {
        int arr[] = {10, 5, 2, 6};
        int k = 100;
        System.out.println(product(arr,k));
    }
    public static int product(int []arr,int k)
    {
        int count=0;
        int pro=1;
        for (int i = 0; i < arr.length; i++) {
            pro=1;
            for (int j = i; j < arr.length; j++) {
                pro*=arr[j];
                if(pro<100)
                count++;
            }
        }
        return count;
    }
}
