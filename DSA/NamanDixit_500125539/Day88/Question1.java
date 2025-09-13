import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Solution {
    // DFS approach to solve the Flood Fill problem
    private void dfs(int row, int col, int[][] image, int newColor, int originalColor) {
        // Base case: check if current pixel is out of bounds or already the new color
        if (row < 0 || row >= image.length || col < 0 || col >= image[0].length ||
            image[row][col] != originalColor) {
            return;
        }

        // Change the color of the current pixel
        image[row][col] = newColor;

        // Recursively call dfs for all 4-directionally adjacent pixels
        dfs(row + 1, col, image, newColor, originalColor);
        dfs(row - 1, col, image, newColor, originalColor);
        dfs(row, col + 1, image, newColor, originalColor);
        dfs(row, col - 1, image, newColor, originalColor);
    }

    // Public method to start the Flood Fill process using DFS
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) {
            return image;
        }
        int originalColor = image[sr][sc];
        dfs(sr, sc, image, newColor, originalColor);
        return image;
    }

    // BFS approach to solve the Flood Fill problem (alternative)
    public int[][] floodFillBFS(int[][] image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) {
            return image;
        }
        int originalColor = image[sr][sc];
        int rows = image.length;
        int cols = image[0].length;

        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{sr, sc});
        image[sr][sc] = newColor;

        int[] dr = {1, -1, 0, 0};
        int[] dc = {0, 0, 1, -1};

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int r = current[0];
            int c = current[1];

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && image[nr][nc] == originalColor) {
                    image[nr][nc] = newColor;
                    queue.offer(new int[]{nr, nc});
                }
            }
        }
        return image;
    }
}

public class Question1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Solution solution = new Solution();

        System.out.println("Enter the number of rows for the image matrix:");
        int rows = scanner.nextInt();
        System.out.println("Enter the number of columns for the image matrix:");
        int cols = scanner.nextInt();

        int[][] image = new int[rows][cols];
        System.out.println("Enter the pixel values for the image matrix (row by row):");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                image[i][j] = scanner.nextInt();
            }
        }

        System.out.println("Enter the starting row (sr):");
        int sr = scanner.nextInt();
        System.out.println("Enter the starting column (sc):");
        int sc = scanner.nextInt();
        System.out.println("Enter the new color:");
        int newColor = scanner.nextInt();

        // Print the original image
        System.out.println("\nOriginal Image:");
        printImage(image);

        // Call the floodFill method
        int[][] resultImage = solution.floodFill(image, sr, sc, newColor);

        // Print the result
        System.out.println("\nImage after Flood Fill:");
        printImage(resultImage);

        scanner.close();
    }

    // Helper method to print the image matrix
    private static void printImage(int[][] image) {
        for (int i = 0; i < image.length; i++) {
            for (int j = 0; j < image[0].length; j++) {
                System.out.print(image[i][j] + " ");
            }
            System.out.println();
        }
    }
}
