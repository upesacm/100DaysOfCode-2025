public class Q2{
    public static int bit(int i,int n)
    {
        int x=n>>i;
        return x&1;

        
    }
    public static void main(String[] args) {
       int y= bit(2,5);
       System.out.println(y);
    }
}
