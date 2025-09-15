import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Solution {
    // Helper class to store coordinates
    class Pair {
        int row;
        int col;

        public Pair(int row, int col) {
            this.row = row;
            this.col = col;
        }
    }

    // BFS (Breadth-First Search) approach to find all connected land cells
    private void bfs(int startRow, int startCol, int[][] grid, boolean[][] visited) {
        int rows = grid.length;
        int cols = grid[0].length;
        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(startRow, startCol));
        visited[startRow][startCol] = true;

        int[] dRows = {-1, 1, 0, 0}; // Directions for up, down, left, right
        int[] dCols = {0, 0, -1, 1};

        while (!queue.isEmpty()) {
            Pair current = queue.poll();
            int currentRow = current.row;
            int currentCol = current.col;

            // Traverse all 4-directional neighbors
            for (int i = 0; i < 4; i++) {
                int newRow = currentRow + dRows[i];
                int newCol = currentCol + dCols[i];

                // Check if the new coordinates are valid, if it's a land cell ('1'), and if it hasn't been visited
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                    grid[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    queue.add(new Pair(newRow, newCol));
                }
            }
        }
    }

    // Main method to find the number of islands
    public int numIslands(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }

        int rows = grid.length;
        int cols = grid[0].length;
        boolean[][] visited = new boolean[rows][cols];
        int islandCount = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // If the cell is unvisited and is part of a new island ('1')
                if (grid[i][j] == 1 && !visited[i][j]) {
                    islandCount++;
                    bfs(i, j, grid, visited);
                }
            }
        }
        return islandCount;
    }
}

public class Question2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Solution solution = new Solution();

        System.out.println("Enter the number of rows for the grid:");
        int rows = scanner.nextInt();
        System.out.println("Enter the number of columns for the grid:");
        int cols = scanner.nextInt();

        int[][] grid = new int[rows][cols];
        System.out.println("Enter the grid values (0 for water, 1 for land) row by row, separated by spaces:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = scanner.nextInt();
            }
        }
        
        System.out.println("\nOriginal Grid:");
        printGrid(grid);

        int numberOfIslands = solution.numIslands(grid);
        System.out.println("\nNumber of islands: " + numberOfIslands);
        
        scanner.close();
    }

    private static void printGrid(int[][] grid) {
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                System.out.print(grid[i][j] + " ");
            }
            System.out.println();
        }
    }
}
