public class Q2 {
    public static void main(String args[])
    {
        int arr[] = {1,8,6,2,5,4,8,3,7};
        System.out.println(water(arr));
    }
    public static int water(int []arr)
    {
        int count=0;
        int max=0;
        for (int i = 0; i < arr.length-1; i++) {
            count=0;
            for (int j = i+1; j < arr.length; j++) {
                count=(j-i)*(arr[i]>arr[j]?arr[j]:arr[i]);
                if(max<count)
                    max=count;
            }
        }
        return max;
    }
}