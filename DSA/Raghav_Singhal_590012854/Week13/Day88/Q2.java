import java.util.*;

class Q2 {
    public static void main(String[] args) {
        int[][] grid = {{1,1,0,0},{1,0,0,1},{0,0,1,1}};
        int count = 0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        System.out.println(count);
    }

    static void dfs(int[][] g, int r, int c){
        if(r<0 || c<0 || r>=g.length || c>=g[0].length || g[r][c]==0) return;
        g[r][c] = 0;
        dfs(g,r+1,c); dfs(g,r-1,c); dfs(g,r,c+1); dfs(g,r,c-1);
    }
}
