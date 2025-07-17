public class Q1{
    public static void powerOf2(int n)
    {
        int y= n & (n-1);
        if(y==0){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
    public static void main(String[] args) {
       powerOf2(2);  
    }
}
