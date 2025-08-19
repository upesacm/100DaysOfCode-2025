import java.util.*;
public class Q3 {
    static class Job {
        int id,d,p;
        Job(int id,int d,int p){this.id=id;this.d=d;this.p=p;}
    }
    public static void main(String[] args) {
        Job[] jobs = {new Job(1,4,20),new Job(2,1,10),new Job(3,1,40),new Job(4,1,30)};
        Arrays.sort(jobs,(a,b)->b.p-a.p);
        int maxd = Arrays.stream(jobs).mapToInt(j->j.d).max().getAsInt();
        int[] slot = new int[maxd+1];
        int cnt=0, profit=0;
        for (Job j: jobs) 
            for (int t=j.d;t>0;t--) 
                if (slot[t]==0){slot[t]=j.id;cnt++;profit+=j.p;break;}
        System.out.println(cnt+" jobs, Profit: "+profit);
    }
}
