public class Q2 {
    public static void main(String args[])
    {
        int Array[]= {1, 2, 2, 2, 3, 4}, Target= 2;
        System.out.println(firOccuBinSearch(Array,Target));
    }
    public static int firOccuBinSearch(int arr[],int Target)
    {
        int left=0,right=arr.length-1,mid;
        int firOccur=-1;
        while (left<=right) 
        {
            mid=(right+left)/2;
            if(Target==arr[mid])
            {
                firOccur=mid;
                right=mid-1;
            }
            else if(arr[mid]>Target)
            {
                right=mid-1;
            }
            else if(arr[mid]<Target)
            {
                left=mid+1;
            }
        }
        return firOccur;
    }
}