public class Q1 
{
    public static void main(String args[])
    {
        int Array[]={10,20,30,40,50}, Target=30;
        System.out.println(linearIndex(Array,Target));
    }
    public static String linearIndex(int arr[],int target)
    {
        for (int idx = 0; idx < arr.length; idx++) {
            if(arr[idx]==target)
            return String.valueOf(idx);            
        }
        return "Element not found";
    }
}