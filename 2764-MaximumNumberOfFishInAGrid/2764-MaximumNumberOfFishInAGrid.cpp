// Last updated: 11/27/2025, 5:17:58 PM
class Solution {
public:
    int rows, cols, directions[5] = {-1, 0, 1, 0, -1};

    int depthFirstSearch(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || !grid[row][col]) 
            return 0;

        int fishCount = grid[row][col];
        grid[row][col] = 0;

        for (int dirIndex = 0; dirIndex < 4; dirIndex++) {
            fishCount += depthFirstSearch(grid, row + directions[dirIndex], col + directions[dirIndex + 1]);
        }

        return fishCount;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int maxFishCount = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col]) {
                    maxFishCount = max(maxFishCount, depthFirstSearch(grid, row, col));
                }
            }
        }

        return maxFishCount;
    }
};
