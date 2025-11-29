// Last updated: 11/29/2025, 4:15:37 PM
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
          int n = grid.size();

        for (int i = 0; i < n; ++i) {
            vector<int> diagonal;
            for (int r = i, c = 0; r < n && c < n; ++r, ++c) {
                diagonal.push_back(grid[r][c]);
            }
           sort(diagonal.rbegin(), diagonal.rend());
            int r = i, c = 0;
            for (int val : diagonal) {
                grid[r++][c++] = val;
            }
        }

        for (int j = 1; j < n; ++j) {
           vector<int> diagonal;
            for (int r = 0, c = j; r < n && c < n; ++r, ++c) {
                diagonal.push_back(grid[r][c]);
            }
           sort(diagonal.begin(), diagonal.end());
            int r = 0, c = j;
            for (int val : diagonal) {
                grid[r++][c++] = val;
            }
        }
        
        return grid;
    }
};
