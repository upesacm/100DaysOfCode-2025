public class Q2 
{
    public static void main(String[] args) 
    {
        String str=" hello  world ";
        System.out.println("Remove all: \""+str.replaceAll(" ","")+"\", Trim: \""+str.trim()+"\", Single spaces: \""+str.trim().replaceAll("\\s+"," ")+"\"");
    }
}