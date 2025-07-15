public class Q3 {
    
    public static void main(String[] args) {
        int arr[]={3, 7, 1, 9, 4, 6};
        System.out.println(maxEle(arr));
    }
    public static int  maxEle(int arr[]) 
    {
        int max=arr[0];
        for (int i =1;i<arr.length;i++) {
            if(arr[i]>max)
            max=arr[i];
        }
        return max;
    }
}
