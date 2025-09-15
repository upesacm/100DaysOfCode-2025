public class Day_88_Question_1 {

    // Flood fill using DFS
    public static int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor == newColor) return image;
        dfs(image, sr, sc, oldColor, newColor);
        return image;
    }

    private static void dfs(int[][] image, int r, int c, int oldColor, int newColor) {
        if (r < 0 || c < 0 || r >= image.length || c >= image[0].length) return;
        if (image[r][c] != oldColor) return;
        image[r][c] = newColor;
        dfs(image, r + 1, c, oldColor, newColor);
        dfs(image, r - 1, c, oldColor, newColor);
        dfs(image, r, c + 1, oldColor, newColor);
        dfs(image, r, c - 1, oldColor, newColor);
    }

    public static void main(String[] args) {
        int[][] img1 = {{1,1,1},{1,1,0},{1,0,1}};
        int[][] res1 = floodFill(img1, 1, 1, 2);
        // Output: [[2,2,2],[2,2,0],[2,0,1]]
        for (int[] row : res1) System.out.println(java.util.Arrays.toString(row));
    }
}
