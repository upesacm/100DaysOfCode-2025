public class Q1{
    public static void oddOrEven(int n)
    {
        if((n&1)==1){
            System.out.println("Odd");
        }else{
            System.out.println("Even");
        }
    }
    public static void main(String[] args) {
        oddOrEven(3);
        oddOrEven(2);
    }
}
