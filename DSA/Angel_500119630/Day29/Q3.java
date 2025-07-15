public class Q3{
    public static void setbit(int n,int i)
    {
        int x=n|(1<<i);
        System.out.println(x);
    }
    public static void main(String[] args) {
       setbit(5, 1);
    }
}
