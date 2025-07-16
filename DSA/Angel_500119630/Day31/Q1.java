public class Day_31_Q1{
    public static void powOf2(int n)
    {
        int y= n & (n-1);
        if(y==0){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }

        
    }
    public static void main(String[] args) {
       powOf2(2);
       powOf2(14);
     
    }
}
