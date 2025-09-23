import java.util.*;

class Q1 {
    public static void main(String[] args) {
        int[][] image = {{1,1,1},{1,1,0},{1,0,1}};
        int sr = 1, sc = 1, newColor = 2;
        int oldColor = image[sr][sc];
        if(oldColor != newColor) dfs(image, sr, sc, oldColor, newColor);
        for(int[] row : image) System.out.println(Arrays.toString(row));
    }
    
    static void dfs(int[][] img, int r, int c, int oldColor, int newColor){
        if(r<0 || c<0 || r>=img.length || c>=img[0].length || img[r][c]!=oldColor) return;
        img[r][c] = newColor;
        dfs(img,r+1,c,oldColor,newColor);
        dfs(img,r-1,c,oldColor,newColor);
        dfs(img,r,c+1,oldColor,newColor);
        dfs(img,r,c-1,oldColor,newColor);
    }
}
