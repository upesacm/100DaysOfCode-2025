public class Q2 {
    public static void main(String[] args) 
    {
        int Array[]= {1, 2, 3, 2, 2, 4}, Target=2;
        System.out.println(Occurence(Array,Target));
    }
    public static int Occurence(int arr[],int target)
    {
        int count=0;
        for (int i : arr) {
            if(i==target)
            count++;
        }
        return count;
    }
}
